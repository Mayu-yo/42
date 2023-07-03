#include "push_swap.h"

void ft_lstnew(t_list **new, int content, int num)
{
	*new = malloc(sizeof(t_list) * 1);
	if (!(*new))
		return ;
	(*new)->index = num;
	(*new)->value = content;
	(*new)->next = NULL;
	(*new)->prev = NULL;
}


int ft_lstsize (t_list *head)
{
	size_t count;
	t_list *tmp;

	if (!head)
		return (0);
	count = 1;
	tmp = head;
	if (tmp->next == NULL)
		return (count);
	while (tmp->next != head)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void ft_addfront(t_list **head, t_list *new)
{
	if (head == NULL || new == NULL)
		return ;
	if ((*head)->next == NULL)
	{
		(*head)->next = new;
		(*head)->prev = new;
		new->next = *head;
		new->prev = *head;
		*head = new;
		return ;
	}
	new->next = *head;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	(*head)->prev = new;
	*head = new;
}
