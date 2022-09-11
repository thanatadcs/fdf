/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:31:36 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/11 22:01:57 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <stdio.h>
void	print_grid(t_grid grid)
{
	t_vec_lst	*cur_vec;

	cur_vec = grid.head;
	int	i = 0;
	while (cur_vec)
	{
		printf("%d = {%f, %f, %f, %d}\n", i++, cur_vec->v.x, cur_vec->v.y, cur_vec->v.z, cur_vec->is_end_line);
		fflush(stdin);
		cur_vec = cur_vec->next;
	}
}

int	main(int ac, char **av)
{
	t_grid	grid;

	if (ac == 2)
	{
		grid = parse_file(av[1]);
		(void) grid;
//		print_grid(grid);
		display_grid_loop(grid);
		free_grid(grid);
	}
	else
	{
		ft_putstr_fd("Usage : ./fdf_demo <filename>", 2);
		return (EXIT_FAILURE);
	}
}
