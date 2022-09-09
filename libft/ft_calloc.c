/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:59:17 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/03 23:52:57 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_mul_overflow(size_t a, size_t b)
{
	size_t	prod;

	if (a == 0 || b == 0)
		return (0);
	prod = a * b;
	if (a == prod / b)
		return (0);
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*to_return;
	size_t	return_len;

	if (is_mul_overflow(count, size))
		return (0);
	return_len = count * size;
	to_return = malloc(return_len * sizeof(char));
	if (to_return == 0)
		return (0);
	ft_bzero(to_return, return_len);
	return (to_return);
}
