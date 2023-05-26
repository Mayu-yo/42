/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:51:14 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 14:59:16 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*p_next;

	if (lst == NULL || *lst == NULL)
		return ;
	p = *lst;
	p_next = p->next;
	while (p_next != NULL)
	{
		p_next = p->next;
		del(p->content);
		free(p);
		p = p_next;
	}
	*lst = NULL;
}
