/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:34:59 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/11 21:59:02 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "fdf.h"
#include <stdio.h>

void	free_grid(t_grid grid)
{
	t_vec_lst	*cur_vec;
	t_vec_lst	*to_free;
	int			i = 0;

	cur_vec = grid.head;
	while (cur_vec)
	{
		to_free = cur_vec;
		cur_vec = cur_vec->next;
		free(to_free);
		i++;
	}
	printf("%d\n", i);
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
		*new_vec = (t_vec_lst){{n_col++ * 10 - C_W / 2, C_H / 2 - grid_ptr->n_row * 10, \
		ft_atoi(*splited_line) * 20, 1}, (splited_line[1] == 0 || *splited_line[1] == '\n'), 0};
		if (grid_ptr->head == 0)
			*grid_ptr = (t_grid){.head = new_vec, .back = new_vec};
		else
		{
			grid_ptr->back->next = new_vec;
			grid_ptr->back = new_vec;
		}
		splited_line++;
	}
	if (grid_ptr->n_col != 0 && grid_ptr->n_col != n_col)
		handle_error(*grid_ptr, "Found wrong line length. Exiting.\n");
	grid_ptr->n_col = n_col;
}

void	transform_coordinate(t_grid grid)
{
	t_vec_lst	*cur_vec;
	double		factor;

	cur_vec = grid.head;
	factor = C_W / grid.n_col;
	printf("%f\n", factor);
	(void) factor;
	while (cur_vec)
	{
		cur_vec->v.x = cur_vec->v.x * factor;
		cur_vec->v.y = cur_vec->v.y * factor;
		cur_vec = cur_vec->next;
	}
}

void	assign_origin(t_grid	*grid)
{
	t_vec_lst	*cur_vec;
	int			i;
	int			j;

	cur_vec = grid->head;
	i = 0;
	j = 0;
	while (cur_vec)
	{
		if (i == grid->n_row / 2 && j == grid->n_col / 2)
			break ;
		cur_vec = cur_vec->next;
		if (j++ == grid->n_col - 1)
		{
			i++;
			j = 0;
		}
	}
	grid->origin = cur_vec;
}

t_grid	parse_file(char *path)
{
	int		fd;
	char	*line;
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
		printf("%d %d\n", to_return.n_row, to_return.n_col);
		free(line);
		line = get_next_line(fd);
		to_return.n_row++;
	}
//	transform_coordinate(to_return);
	assign_origin(&to_return);
	return (to_return);
}
