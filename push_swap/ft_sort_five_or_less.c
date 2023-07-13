/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_or_less.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:48:18 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 12:52:48 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->value;
	b = (*list)->next->value;
	c = (*list)->next->next->value;
	if (a < b && b > c && c > a)
	{
		sa(list);
		ra(list);
	}
	else if (a > b && b < c && c > a)
		sa(list);
	else if (a < b && b > c && c < a)
		rra(list);
	else if (a > b && b < c && c < a)
		ra(list);
	else if (a > b && b > c && c < a)
	{
		sa(list);
		rra(list);
	}
}

void	ft_sort_five_or_less(t_list **stack_a, t_list **stack_b, int argc)
{
	int	i;
	int	distance;

	i = 0;
	distance = count_distance(*stack_a, i);
	while (i < argc - 4)
	{
		if ((*stack_a)->index == i)
		{
			pb(stack_a, stack_b);
			i++;
			distance = count_distance(*stack_a, i);
		}
		else if (distance <= ft_lstsize(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
