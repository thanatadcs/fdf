/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:34:59 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/10 01:11:50 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "fdf.h"

void	free_grid(t_grid grid)
{
	t_vec_lst	*cur_vec;
	t_vec_lst	*to_free;

	cur_vec = grid.head;
	while (cur_vec)
	{
		to_free = cur_vec;
		cur_vec = cur_vec->next;
		free(cur_vec);
	}
}

void	handle_error(t_grid grid, char *msg)
{
	free_grid(grid);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	append_grid(t_grid *grid_ptr, char *line)
{
	int			n_col;	
	char		**splited_line;
	t_vec_lst	*new_vec;	

	n_col = 0;
	splited_line = ft_split(line, ' ');
	while (*splited_line && **splited_line != '\n')
	{
		new_vec = malloc(sizeof(t_vec_lst));
		if (new_vec == 0)
			handle_error(*grid_ptr, "Error while trying to malloc\n");
		*new_vec = (t_vec_lst){{n_col, grid_ptr->n_row, \
		ft_atoi(*splited_line++), 1}, (n_col == grid_ptr->n_col - 1), 0};
		if (grid_ptr->head == 0)
			*grid_ptr = (t_grid){.head = new_vec, .back = new_vec};
		else
		{
			grid_ptr->back->next = new_vec;
			grid_ptr->back = new_vec;
		}
		n_col++;
	}
	if (grid_ptr->n_col != 0 && grid_ptr->n_col != n_col)
		handle_error(*grid_ptr, "Found wrong line length. Exiting.\n");
	grid_ptr->n_col = n_col;
}

t_grid	parse_file(char *path)
{
	int		fd;
	char	*line;
	char	**cols;
	t_grid	to_return;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(0);
		exit(EXIT_FAILURE);
	}
	to_return = (t_grid){0};
	line = get_next_line(fd);
	while (line)
	{
		append_grid(&to_return, line);
		line = get_next_line(fd);
		to_return.n_row++;
	}
	return (to_return);
}
