/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:50:23 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 11:32:32 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	return_len;
	char	*to_return;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (s_len - start > len)
		return_len = len;
	else
		return_len = s_len - start;
	to_return = malloc((return_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	ft_strlcpy(to_return, s + start, return_len + 1);
	return (to_return);
}
