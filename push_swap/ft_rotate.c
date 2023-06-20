#include "push_swap.h"

int ra(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->next;
	ft_putendl_fd("ra", 1);
	return (0);
}

int rb(t_list **head)
{
	if (!(head) || !(*head) || ft_lstsize(*head) < 2)
		return (-1);
	*head = (*head)->next;
	ft_putendl_fd("rb", 1);
	return (0);
}

int rr(t_list **a, t_list **b)
{
	if (ra(a) == -1 || rb(b) == -1)
		return (-1);
	ft_putendl_fd("rr", 1);
	return (0);
}
