/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:47:47 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 12:47:48 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **a, t_list **b)
{
	t_list	*new;

	if (!b || !(*b))
		return (-1);
	if (!(*a))
	{
		ft_lstnew(a, (*b)->value, (*b)->index);
		if (!a)
			return (-1);
	}
	else
	{
		ft_lstnew(&new, (*b)->value, (*b)->index);
		if (!new)
			return (-1);
		ft_addfront(a, new);
	}
	ft_lstdelone(b);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	t_list	*new;

	if (!a || !(*a))
		return (-1);
	if (!(*b))
	{
		ft_lstnew(b, (*a)->value, (*a)->index);
		if (!b)
			return (-1);
	}
	else
	{
		ft_lstnew(&new, (*a)->value, (*a)->index);
		if (!new)
			return (-1);
		ft_addfront(b, new);
	}
	ft_lstdelone(a);
	ft_putendl_fd("pb", 1);
	return (0);
}
