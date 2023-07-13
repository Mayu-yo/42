/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:47:50 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 12:51:54 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->prev;
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->prev;
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if (!(a) || !(*a) || ft_lstsize(*a) < 2)
		return (-1);
	if (!(b) || !(*b) || ft_lstsize(*b) < 2)
		return (-1);
	(*a) = (*a)->prev;
	(*b) = (*b)->prev;
	ft_putendl_fd("rrr", 1);
	return (0);
}
