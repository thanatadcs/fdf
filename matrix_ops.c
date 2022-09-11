/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:25:39 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/11 14:23:49 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "fdf.h"

t_matrix	matrix_multiply(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	int			k;
	t_matrix	to_return;

	k = 0;
	while (k < 4)
	{	
		i = 0;
		while (i < 4)
		{
			j = 0;
			to_return.data[i][k] = 0;
			while (j < 4)
			{
				to_return.data[i][k] += a.data[i][j] * b.data[j][k];
				j++;
			}
			i++;
		}
		k++;
	}
	return (to_return);
}

t_vec_h	matrix_vector_multiply(t_matrix m, t_vec_h v)
{
	return ((t_vec_h){m.data[0][0] * v.x + m.data[0][1] * v.y \
	+ m.data[0][2] * v.z + m.data[0][3] * v.h, \
	m.data[1][0] * v.x + m.data[1][1] * v.y \
	+ m.data[1][2] * v.z + m.data[1][3] * v.h, \
	m.data[2][0] * v.x + m.data[2][1] * v.y \
	+ m.data[2][2] * v.z + m.data[2][3] * v.h, \
	m.data[3][0] * v.x + m.data[3][1] * v.y \
	+ m.data[3][2] * v.z + m.data[3][3] * v.h, \
	});
}
