/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:49:48 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/10 12:39:38 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "minilibx_macos/mlx.h"
#include "fdf.h"

static void	pixel_put(t_vec_2d v, int color)
{
	int			new_x;
	int			new_y;
	t_mlx_var	var;

	new_x = C_W / 2 + v.x;
	new_y = C_H / 2 - v.y;
	var = initialize();
	mlx_pixel_put(var.mlx, var.win, new_x, new_y, color);
}

static void	swap(t_vec_2d *p0, t_vec_2d *p1)
{
	t_vec_2d	tmp;

	tmp = *p0;
	*p0 = *p1;
	*p1 = tmp;
}

static void	draw_line_helper(t_vec_2d p0, t_vec_2d p1, \
int color, int is_inv)
{
	double	m;
	double	b;
	double	*i;
	double	*d;

	i = (double []){p0.x, p1.x};
	d = (double []){p0.y, p1.y};
	if (is_inv)
	{
		i = (double []){p0.y, p1.y};
		d = (double []){p0.x, p1.x};
	}
	m = (d[1] - d[0]) / (i[1] - i[0]);
	b = d[0] - m * i[0];
	d[0] = m * i[0] + b;
	while (i[0] <= i[1])
	{
		if (is_inv)
			pixel_put((t_vec_2d){d[0], i[0]}, color);
		else
			pixel_put((t_vec_2d){i[0], d[0]}, color);
		d[0] += m;
		i[0]++;
	}
}

void	draw_line(t_vec_2d p0, t_vec_2d p1, int color)
{
	double	dy;
	double	dx;

	dy = fabs(p1.y - p0.y);
	dx = fabs(p1.x - p0.x);
	if (dx > dy)
	{
		if (p0.x > p1.x)
			swap(&p0, &p1);
		draw_line_helper(p0, p1, color, 0);
	}
	else
	{
		if (p0.y > p1.y)
			swap(&p0, &p1);
		draw_line_helper(p0, p1, color, 1);
	}
}
