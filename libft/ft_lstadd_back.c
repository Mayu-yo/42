/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:50:28 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 14:59:02 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list*new)
{
	t_list	*last_p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_p = *lst;
	last_p->next = new;
}
