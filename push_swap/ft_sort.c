#include "push_swap.h"

size_t count_distance(t_list *stack_a, int i)//前から数えた距離を返す
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = stack_a;
	while (tmp->index != i)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

// void ft_push_to_stackb(t_list **stack_a, t_list **stack_b, int i, int num)
// {
// 	static int count;

// 	while (count < (num * (i + 1)) && *stack_a)
// 	{
// 		if ((*stack_a)->index < (num * i))
// 		{
// 			pb(stack_a, stack_b);
// 			count++;
// 		}
// 		else if ((*stack_a)->index < (num * (i + 1)))
// 		{
// 			pb(stack_a, stack_b);
// 			if ((*stack_a)->index < (num * (i + 1)))
// 				rb(stack_b);
// 			else
// 				rr(stack_a, stack_b);
// 			count++;
// 		}
// 		else
// 			ra(stack_a);
// 	}
// }

void ft_push_to_stackb(t_list **stack_a, t_list **stack_b, int i, int num)
{
	static int count;

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
			rb(stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
}

void ft_sort(t_list **stack_a, t_list **stack_b, int stack_size)
{
	int num;
	int count;

	num = 10 + (stack_size / 25);
	count = 1;
	while (*stack_a)
	{
		ft_push_to_stackb(stack_a, stack_b, count, num);
		count += 2;
	}
	ft_return(stack_a, stack_b, stack_size - 1);
}
