/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:48:13 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 12:48:14 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->next;
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->next;
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	if (!(a) || !(*a) || ft_lstsize(*a) < 2)
		return (-1);
	if (!(b) || !(*b) || ft_lstsize(*b) < 2)
		return (-1);
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	ft_putendl_fd("rr", 1);
	return (0);
}
