/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:32:01 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/01 17:12:30 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
	{
		while (i < len)
		{
			*((char *) dst + len - i - 1) = *((char *) src + len - i - 1);
			i++;
		}
	}
	return (dst);
}
