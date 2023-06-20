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

void ft_sort_six_or_less(t_list **list, int argc)
{

}