#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list*new)
{
	t_list *last_p;

	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	last_p = *lst;
	last_p->next = new;
}