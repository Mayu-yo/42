#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *p;
	t_list *p_next;

	if (lst == NULL || *lst == NULL)
		return;
	p = *lst;
	p_next = p->next;
	while (p_next != NULL)
	{
		p_next = p->next;
		del(p->content);
		free(p);
		p = p_next;
	}
	*lst = NULL;
}