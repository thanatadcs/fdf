/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:15:35 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 14:24:27 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*to_return;

	to_return = malloc(sizeof(t_list));
	if (to_return == 0)
		return (0);
	to_return->content = content;
	to_return->next = 0;
	return (to_return);
}
