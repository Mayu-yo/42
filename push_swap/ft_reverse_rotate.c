#include "push_swap.h"

int rra(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->prev;
	ft_putendl_fd("rra", 1);
	return (0);
}

int rrb(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->prev;
	ft_putendl_fd("rrb", 1);
	return (0);
}

int rrr(t_list **a, t_list **b)
{
	if (rra(a) == -1 || rrb(b) == -1)
		return (-1);
	(*a) = (*a)->prev;
	(*b) = (*b)->prev;
	ft_putendl_fd("rrr", 1);
	return (0);
}