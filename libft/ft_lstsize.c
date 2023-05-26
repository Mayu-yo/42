#include "libft.h"

int ft_lstsize(t_list *lst)
{
	t_list *p;
	int count;

	count = 0;
	p = lst;
	if(lst == NULL)
		return (0);
	if(lst->next == NULL)
		return (1);
	while (p->next != NULL)
	{
		p++;
		count++;
	}
	return (count + 2);
}