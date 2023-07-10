/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:49:34 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 13:16:00 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_distance(t_list *stack_a, int i)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = stack_a;
	while (tmp->index != i)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	ft_temporary_relocation(t_list **stack_a, t_list **stack_b, int i)
{
	if (i == 2)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else
	{
		while (i > 1)
		{
			ra(stack_a);
			i--;
		}
		pa(stack_a, stack_b);
		while ((*stack_a)->index > (*stack_a)->prev->index)
			rra(stack_a);
	}
}
