#include "push_swap.h"

int pa(t_list **a, t_list **b)
{
	t_list *new;

	if (!a || !(*a) || !b || !(*b))
		return (-1);
	ft_lstnew(&new, (*b)->value);
	if (!new)
		return (-1);
	ft_lstdelone(&(*b));
	ft_addfront(&(*a), new);
	ft_putendl_fd("pa", 1);
	return (0);
}

int pb(t_list **a, t_list **b)
{
	t_list *new;

	if (!a || !(*a) || !b || !(*b))
		return (-1);
	ft_lstnew(&new, (*a)->value);
	if (!new)
		return (-1);
	ft_lstdelone(&(*a));
	ft_addfront(&(*b), new);
	ft_putendl_fd("pb", 1);
	return (0);
}
