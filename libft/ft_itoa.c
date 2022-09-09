/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:29:28 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 12:54:20 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

static int	count_digit(int n)
{
	if (n == -2147483648)
		return (10);
	else if (my_abs(n) <= 9)
		return (1);
	else
		return (count_digit(my_abs(n) / 10) + 1);
}

char	*ft_itoa(int n)
{
	int		return_len;
	char	*to_return;
	int		is_neg;

	return_len = count_digit(n);
	is_neg = n < 0;
	return_len += is_neg;
	to_return = malloc((return_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	to_return[return_len--] = '\0';
	while (return_len >= 0)
	{
		if (is_neg && return_len == 0)
		{
			to_return[return_len] = '-';
			break ;
		}
		to_return[return_len--] = my_abs(n % 10) + '0';
		n /= 10;
	}
	return (to_return);
}
