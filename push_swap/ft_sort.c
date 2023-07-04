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

// void ft_sort_six_or_less(t_list **stack_a, t_list **stack_b, int argc)
// {
// 	int i;

// 	i = 0;
// 	while (i < argc - 4)
// 	{
// 		if ((*stack_a)->index == i)
// 		{
// 			pb(stack_a, stack_b);
// 			i++;
// 		}
// 		else
// 			ra(stack_a);
// 	}
// 	ft_sort_three(stack_a);
// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// }

void ft_sort_six_or_less(t_list **stack_a, t_list **stack_b, int argc)
{
	int i;

	i = 0;
	while (i < argc - 4)
	{
		if ((*stack_a)->index < argc - 4)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	ft_sort_three(stack_a);
	ft_sort_three(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void ft_sort() {
	
}