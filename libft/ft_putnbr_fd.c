/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:53:46 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 12:54:03 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (my_abs(n) <= 9)
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(my_abs(n) + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(my_abs(n % 10), fd);
	}
}
