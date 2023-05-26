#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *next_node;
	next_node = (t_list *)malloc(1);
	if (next_node == NULL)
		return (NULL);
	next_node->content = content;
	next_node->next = NULL;
	return next_node;
}
