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

// void ft_sort(t_list **stack_a, t_list **stack_b, int stack_size) {
// 	int count;

// 	count = 0;
// 	if (stack_size - 1 == 1)
// 		return ;
// 	while (stack_size - 1 > count)
// 	{
// 		if ((*stack_a)->index < stack_size / 2)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 		count++;
// 	}
// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// 	ft_sort(stack_a, stack_b, stack_size / 2);
// }


//quick sort example
void	ft_quick_sort(int *array, int start, int end)
{
	int q;

	if (start < end)
	{
		q = ft_partition(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	}
}

int		ft_partition(int *array, int start, int end)
{
	int pivot;
	int i;
	int temp;
	int j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}