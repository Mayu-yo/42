/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:52:36 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 14:52:38 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		count;

	count = 0;
	p = lst;
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (1);
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return (count);
}
