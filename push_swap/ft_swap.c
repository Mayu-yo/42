/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:49:38 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/14 09:44:53 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *node)
{
	t_list	tmp;

	if (!node || !node->next)
		return ;
	tmp = *node;
	node->value = node->next->value;
	node->next->value = tmp.value;
	node->index = node->next->index;
	node->next->index = tmp.index;
}

int	sa(t_list **a)
{
	if (!a || !(*a) || ft_lstsize(*a) < 2)
		return (-1);
	ft_swap (*a);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **b)
{
	if (!b || !(*b) || ft_lstsize(*b) < 2)
		return (-1);
	ft_swap (*b);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	if (!a || !(*a) || ft_lstsize(*a) < 2)
		return (-1);
	if (!b || !(*b) || ft_lstsize(*b) < 2)
		return (-1);
	ft_swap (*a);
	ft_swap (*b);
	ft_putendl_fd("ss", 1);
	return (0);
}
