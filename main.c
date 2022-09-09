/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:31:36 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/10 01:13:46 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

void	print_grid(t_grid grid)
{
	t_vec_lst	*cur_vec;

	cur_vec = grid.head;
	while (cur_vec)
	{
		printf("{%f, %d }", cur_vec->v.z, cur_vec->is_end_line);
		cur_vec = cur_vec->next;
	}
}

int	main(int ac, char **av)
{
	t_grid	grid;

	if (ac == 2)
	{
		grid = parse_file(av[1]);
		print_grid(grid);
		free_grid(grid);
	}
	else
	{
		ft_printf("Usage : ./fdf_demo <filename>");
		return (EXIT_FAILURE);
	}
}
