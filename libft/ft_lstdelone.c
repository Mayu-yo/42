/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:51:28 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 15:00:01 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*lst_next;

	if (lst == NULL || del == NULL)
		return ;
	lst_next = lst->next;
	del(lst->content);
	free(lst);
	if (lst_next != NULL)
		lst->next = lst_next;
	else
		lst->next = NULL;
}
