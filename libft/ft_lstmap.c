/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:32:44 by tanukool          #+#    #+#             */
/*   Updated: 2022/06/08 17:28:23 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*nodemap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	void	*new_content;

	new_content = f(lst->content);
	new_node = ft_lstnew(new_content);
	if (new_node == 0)
	{
		del(new_content);
		return (0);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*to_return;
	t_list	*cur_node;
	t_list	*new_node;

	to_return = 0;
	while (lst)
	{
		new_node = nodemap(lst, f, del);
		if (new_node == 0)
		{
			ft_lstclear(&to_return, del);
			return (0);
		}
		if (to_return == 0)
			to_return = new_node;
		else
			cur_node->next = new_node;
		cur_node = new_node;
		lst = lst->next;
	}
	return (to_return);
}
