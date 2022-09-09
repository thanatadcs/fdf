/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:15:00 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 17:42:15 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur_node;
	t_list	*prev_node;

	if (lst == 0)
		return ;
	cur_node = *lst;
	while (cur_node)
	{
		prev_node = cur_node;
		cur_node = cur_node->next;
		ft_lstdelone(prev_node, del);
	}
	*lst = 0;
}
