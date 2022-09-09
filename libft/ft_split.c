/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:03:02 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 13:23:32 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen_until(const char *s1, char c)
{
	size_t	i;

	i = 0;
	if (s1 == 0)
		return (0);
	while (s1[i] && s1[i] != c)
		i++;
	return (i);
}

static char	*my_strdup_until(const char *s1, char c)
{
	char	*to_return;
	size_t	s1_len;
	size_t	i;

	if (s1 == 0)
		return (0);
	s1_len = my_strlen_until(s1, c);
	to_return = malloc((s1_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] != c)
	{
		to_return[i] = s1[i];
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	int		is_word;

	count = 0;
	is_word = 1;
	if (s == 0)
		return (0);
	while (*s)
	{
		if (*s == c)
			is_word = 1;
		else if (is_word)
		{
			count++;
			is_word = 0;
		}
		s++;
	}
	return (count);
}

static char	**free_until(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n)
		free(strs[i++]);
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**to_return;
	size_t	i;

	if (s == 0)
		return (0);
	to_return = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (to_return == 0)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		to_return[i] = my_strdup_until(s, c);
		if (to_return[i] == 0)
			return (free_until(to_return, i));
		i++;
		while (*s && *s != c)
			s++;
	}
	to_return[i] = 0;
	return (to_return);
}
