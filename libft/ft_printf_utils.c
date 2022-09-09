/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:50:57 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/12 01:49:32 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	num_printed;
	int	buf;

	num_printed = 0;
	if (s == 0)
	{
		buf = write(1, "(null)", 6);
		if (buf == -1)
			return (-1);
		return (buf);
	}
	while (*s)
	{
		buf = write(1, s++, 1);
		if (buf == -1)
			return (-1);
		num_printed += buf;
	}
	return (num_printed);
}

int	ft_putnbr(long n)
{
	int	num_printed;
	int	buf[2];

	buf[0] = 0;
	buf[1] = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		buf[0] = ft_putnbr(-1 * n);
		buf[0] += (buf[0] != -1);
	}
	else if (n > 9 && n / 10 > 0)
	{
		buf[0] = ft_putnbr(n / 10);
		if (buf[0] == -1)
			return (-1);
		buf[1] = ft_putchar(n % 10 + '0');
	}
	else
		buf[0] = ft_putchar(n + '0');
	if (buf[0] == -1 || buf[1] == -1)
		return (-1);
	num_printed = buf[0] + buf[1];
	return (num_printed);
}

int	ft_puthex(uintptr_t n, int print_upper)
{
	char	*hex;
	char	*hex_lower;
	char	*hex_upper;
	int		num_printed;
	int		buf[2];

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	hex = hex_lower;
	buf[0] = 0;
	buf[1] = 0;
	if (print_upper)
		hex = hex_upper;
	if (n >= 16)
	{
		buf[0] = ft_puthex(n / 16, print_upper);
		if (buf[0] == -1)
			return (-1);
	}
	buf[1] = ft_putchar(hex[n % 16]);
	if (buf[1] == -1)
		return (-1);
	num_printed = buf[0] + buf[1];
	return (num_printed);
}
