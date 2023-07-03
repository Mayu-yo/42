#include "push_swap.h"



int pb(t_list **a, t_list **b)
{
	t_list *new;

	if (!a || !(*a))
		return (-1);
	if (!(*b))
	{
		ft_lstnew(b, (*a)->value, (*a)->index);
		if (!b)
			return (-1);
	}
	else
	{
		ft_lstnew(&new, (*a)->value, (*a)->index);
		if (!new)
			return (-1);
		ft_addfront(b, new);
	}
	ft_lstdelone(a);
	ft_putendl_fd("pb", 1);
	return (0);
}
