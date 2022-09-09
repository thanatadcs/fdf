/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:29:11 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/03 17:53:03 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*to_return;
	char	cc;

	to_return = 0;
	cc = (char) c;
	while (*s)
	{
		if (*s == cc)
			to_return = (char *) s;
		s++;
	}
	if (*s == cc)
		to_return = (char *) s;
	return (to_return);
}
