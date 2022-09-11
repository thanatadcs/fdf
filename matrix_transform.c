/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:27:10 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/11 14:24:02 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "fdf.h"

t_matrix	rotate_x_matrix(double	theta)
{
	return ((t_matrix)\
	{{\
	{1, 0, 0, 0},\
	{0, cos(theta), -1 * sin(theta), 0}, \
	{0, sin(theta), cos(theta), 0}, \
	{0, 0, 0, 1}\
	}});
}

t_matrix	rotate_y_matrix(double	theta)
{
	return ((t_matrix)\
	{{\
	{cos(theta), 0, sin(theta), 0}, \
	{0, 1, 0, 0}, \
	{-1 * sin(theta), 0, cos(theta), 0}, \
	{0, 0, 0, 1}\
	}});
}

t_matrix	rotate_z_matrix(double	theta)
{
	return ((t_matrix)\
	{{\
	{cos(theta), -1 * sin(theta), 0}, \
	{sin(theta), cos(theta), 0}, \
	{0, 0, 1, 0}, \
	{0, 0, 0, 1}\
	}});
}

t_matrix	translate_matrix(double x, double y, double z)
{
	return ((t_matrix)\
	{{\
	{1, 0, 0, x}, \
	{0, 1, 0, y}, \
	{0, 0, 1, z}, \
	{0, 0, 0, 1}\
	}});
}

t_matrix	scale_matrix(double k)
{
	return ((t_matrix){{\
	{k, 0, 0, 0}, \
	{0, k, 0, 0}, \
	{0, 0, k, 0}, \
	{0, 0, 0, 1}, \
	}});
}
