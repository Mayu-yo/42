#include "push_swap.h"

static t_list *ft_get_next_min(t_list *list, int argc)
{
	t_list *tmp;
	static t_list *min;

	tmp = list;
	if (!min)
		min = tmp;
	else
	{
		while (min->index != -1)
			min = min->next;
	}
	while (argc - 1)
	{
		if (tmp->value < min->value && tmp->index == -1)
			min = tmp;
		tmp = tmp->next;
		argc--;
	}
	return (min);
}

void ft_assign_index(t_list **list, int argc)
{
	t_list *min;
	int i;

	i = 0;
	while (i < argc - 1)
	{
		min = ft_get_next_min(*list, argc);
		min->index = i;
		i++;
	}
}
