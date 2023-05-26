#include "libft.h"

// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	size_t len;
// 	t_list *new;

// 	len = 0;
// 	if(lst == NULL)
// 		return (NULL);
// 	while(lst->next != NULL)
// 		len++;
// 	new = (t_list *)malloc(len + 1);
// 	while(new->next != NULL)
// 	{
// 		new->content = (*f)(lst->content);
// 		new->next = lst->next;
// 		free(lst);
// 	}
// 	new->content = (*f)(lst->content);
// 	new->next = NULL;
// 	return (new);
// }