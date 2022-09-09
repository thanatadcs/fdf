/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:23:51 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 11:35:43 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*to_return;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	to_return = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	ft_strlcpy(to_return, s1, s1_len + 1);
	ft_strlcat(to_return + s1_len, s2, s1_len + s2_len + 1);
	return (to_return);
}
