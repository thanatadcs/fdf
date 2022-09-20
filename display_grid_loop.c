/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:07:00 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/20 22:37:48 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "minilibx_macos/mlx.h"
#include "fdf.h"

t_mlx_var	initialize(void)
{
	static t_mlx_var	var;

	if (var.mlx == 0)
	{
		var.mlx = mlx_init();
		var.win = mlx_new_window(var.mlx, C_W, C_H, "fdf");
	}
	return (var);
}

t_vec_2d	orthogonal_projection(t_vec_lst v0)
{
	return ((t_vec_2d){v0.v.x, v0.v.y});
}

void	render_col(t_vec_lst *line1, t_vec_lst *line2)
{
	while (line1 && line2 && !line1->is_end_line)
	{
		draw_line(orthogonal_projection(*line1), \
		orthogonal_projection(*line2), 0xFFFFFF);
		line1 = line1->next;
		line2 = line2->next;
	}
	if (line1 && line2)
		draw_line(orthogonal_projection(*line1), \
		orthogonal_projection(*line2), 0xFFFFFF);
}

void	render_row(t_vec_lst *line)
{
	while (line && !line->is_end_line) {
		if (line->next)
		{
			draw_line(orthogonal_projection(*line), \
			orthogonal_projection(*line->next), 0xFFFFFF);
		}
		line = line->next;
	}
}

void	render_grid(t_grid grid)
{
	t_vec_lst	*cur_line;
	t_vec_lst	*prev_line;

	cur_line = grid.head;
	prev_line = 0;
	render_row(cur_line);
	while (cur_line)
	{
		prev_line = cur_line;
		while (cur_line && !cur_line->is_end_line)
			cur_line = cur_line->next;
		if (!cur_line)
			break ;
		cur_line = cur_line->next;
		render_row(cur_line);
		render_col(prev_line, cur_line);
	}
}

void	transform_grid(t_grid grid, t_matrix m)
{
	t_vec_lst	*cur_vec;

	cur_vec = grid.head;
	while (cur_vec)
	{
		cur_vec->v = matrix_vector_multiply(m, cur_vec->v);
		cur_vec = cur_vec->next;
	}
}

int	handle_key(int key, void *param)
{
	double		theta;
	t_grid		grid;
	t_mlx_var	var;

	var = initialize();
	grid = *(t_grid *)param;
	theta = 0;
	if (key != 123 && key != 124)
		return (1);
	if (key == 123)
		theta -= 10;
	else if (key == 124)
		theta += 10;
	transform_grid(grid, rotate_y_matrix(theta * M_PI / 180));
	mlx_clear_window(var.mlx, var.win);
	render_grid(grid);
	return (0);
}

void	display_grid_loop(t_grid grid)
{
	t_mlx_var	var;
	t_matrix	t;
	t_matrix	rx;
	t_matrix	ry;
	t_matrix	rz;
	t_matrix	m;

	var = initialize();
	t = translate_matrix(-1 * grid.origin->v.x, -1 * grid.origin->v.y, 0);
	rz = rotate_z_matrix(45 * M_PI / 180);
	ry = rotate_y_matrix(0);
	rx = rotate_x_matrix(-35.245 * M_PI / 180);
	m = matrix_multiply(rz, t);
	m = matrix_multiply(ry, m);
	m = matrix_multiply(rx, m);
	transform_grid(grid, m);
	render_grid(grid);
	mlx_key_hook(var.win, handle_key, &grid);
	mlx_loop(var.mlx);
}
