/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:02:09 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/10 00:36:57 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	my_isspace(int c)
{
	unsigned char	cc;

	cc = (unsigned char) c;
	return ((cc >= '\t' && cc <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	long	to_return;
	int		sign;

	to_return = 0;
	sign = 1;
	while (*str && my_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		if (to_return > to_return * 10 + *str - '0')
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		to_return = to_return * 10 + *str++ - '0';
	}
	return (sign * to_return);
}
