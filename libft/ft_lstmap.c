/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:52:06 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 15:10:33 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*current;

	new_list = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (new_list == NULL)
			new_list = new_node;
		else
			current->next = new_node;
		current = new_node;
		lst = lst->next;
	}
	current->next = NULL;
	return (new_list);
}
