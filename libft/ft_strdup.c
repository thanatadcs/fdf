/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 04:14:32 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/03 17:30:43 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*to_return;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	to_return = malloc((s1_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	ft_strlcpy(to_return, s1, s1_len + 1);
	return (to_return);
}
