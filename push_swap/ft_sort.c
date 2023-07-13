/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:49:34 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 13:17:08 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_to_stacka(t_list **stack_a, t_list **stack_b, int lstsize)
{
	int	i;
	int	distance;

	i = 1;
	distance = count_distance(*stack_b, lstsize);
	while ((*stack_b)->index != lstsize)
	{
		if ((*stack_b)->index == lstsize - i)
		{
			pa(stack_a, stack_b);
			i++;
		}
		else
		{
			if (distance <= lstsize / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
	return (i);
}

void	ft_return(t_list **stack_a, t_list **stack_b, int lstsize)
{
	int	i;

	lstsize = lstsize - 1;
	while (*stack_b)
	{
		i = ft_push_to_stacka(stack_a, stack_b, lstsize);
		if (i > 1)
		{
			ft_temporary_relocation(stack_a, stack_b, i);
			lstsize = lstsize - i + 1;
		}
		else
			pa(stack_a, stack_b);
		i = 1;
		lstsize--;
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int stack_size)
{
	int	num;
	int	count;

	num = 10 + (stack_size / 25);
	count = 1;
	while (*stack_a)
	{
		ft_push_to_stackb(stack_a, stack_b, count, num);
		count += 2;
	}
	ft_return(stack_a, stack_b, stack_size - 1);
}

void	ft_push_to_stackb(t_list **stack_a, t_list **stack_b, int i, int num)
{
	static int	count;

	while (count < (num * (i + 1)) && *stack_a)
	{
		if ((*stack_a)->index < (num * i))
		{
			pb(stack_a, stack_b);
			count++;
		}
		else if ((*stack_a)->index < (num * (i + 1)))
		{
			pb(stack_a, stack_b);
			if (*stack_a && (*stack_a)->index >= (num * (i + 1)))
			{
				rr(stack_a, stack_b);
			}
			else
			{
				rb(stack_b);
			}
			count++;
		}
		else
			ra(stack_a);
	}
}
