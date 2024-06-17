/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:41:41 by margarita         #+#    #+#             */
/*   Updated: 2024/06/17 13:27:29 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(struct s_list));
	if (!new_list)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
