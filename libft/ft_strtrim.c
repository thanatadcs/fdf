/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:48:54 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 11:39:41 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_contain(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == 0)
		return (0);
	else if (*s1 == '\0' || *set == '\0')
		return (ft_strdup(s1));
	start = 0;
	end = 0;
	while (is_contain(s1[start], set))
		start++;
	while (s1[end])
		end++;
	if (s1[start] == '\0' || end == 0)
		return (ft_calloc(1, 1));
	while (end >= 1 && is_contain(s1[end - 1], set))
		end--;
	if (start > end)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, start, end - start));
}
