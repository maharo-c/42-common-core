/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:49:54 by margarita         #+#    #+#             */
/*   Updated: 2024/06/18 01:13:11 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*new_node;
	t_list	*map_content;

	if (!lst || !f || !del)
		return (NULL);
	lst_map = NULL;
	while (lst)
	{
		map_content = f(lst->content);
		new_node = ft_lstnew(map_content);
		if (!new_node)
		{
			if (map_content)
				del(map_content);
			ft_lstclear(&lst_map, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_map, new_node);
		lst = lst->next;
	}
	return (lst_map);
}
