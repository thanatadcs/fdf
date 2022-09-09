/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:55:48 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 11:52:11 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*to_return;
	size_t	return_len;
	size_t	i;

	if (s == 0 || f == 0)
		return (0);
	return_len = ft_strlen(s);
	to_return = malloc((return_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	i = 0;
	while (i < return_len)
	{
		to_return[i] = f(i, s[i]);
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}
