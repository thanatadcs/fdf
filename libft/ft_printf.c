/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:20:35 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/12 01:49:00 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(const char *s, va_list *args_ptr)
{
	int	to_return;

	to_return = 0;
	if (*s == 'c')
		to_return = ft_putchar(va_arg(*args_ptr, int));
	else if (*s == 's')
		to_return = ft_putstr(va_arg(*args_ptr, char *));
	else if (*s == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		to_return = ft_puthex(va_arg(*args_ptr, uintptr_t), 0);
		if (to_return == -1)
			return (-1);
		to_return += 2;
	}
	else if (*s == 'd' || *s == 'i')
		to_return = ft_putnbr(va_arg(*args_ptr, int));
	else if (*s == 'u')
		to_return = ft_putnbr(va_arg(*args_ptr, unsigned int));
	else if (*s == 'x' || *s == 'X')
		to_return = ft_puthex(va_arg(*args_ptr, unsigned int), (*s == 'X'));
	else if (*s == '%' || *s != '\0')
		to_return = ft_putchar(*s);
	return (to_return);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		num_printed;
	int		buf;

	va_start(args, s);
	num_printed = 0;
	while (*s)
	{
		if (*s == '%')
			buf = check_flag(++s, &args);
		else
			buf = write(1, s, 1);
		if (buf == -1)
			return (-1);
		num_printed += buf;
		s += (*s != '\0');
	}
	va_end(args);
	return (num_printed);
}
