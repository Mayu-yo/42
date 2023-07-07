#include "push_swap.h"

void ft_sort_three(t_list **list)
{
	int a;
	int b;
	int c;

	a = (*list)->value;
	b = (*list)->next->value;
	c = (*list)->next->next->value;
	if (a < b && b > c && c > a)//132
	{
		sa(list);
		ra(list);
	}
	else if (a > b && b < c && c > a)//213
		sa(list);
	else if (a < b && b > c && c < a)//231
		rra(list);
	else if (a > b && b < c && c < a)//312
		ra(list);
	else if (a > b && b > c && c < a)//321
	{
		sa(list);
		rra(list);
	}
}

void ft_sort_six_or_less(t_list **stack_a, t_list **stack_b, int argc)
{
	int i;
	int distance;

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
