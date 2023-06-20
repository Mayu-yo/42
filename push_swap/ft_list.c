#include "push_swap.h"

void ft_lstnew(t_list **new, int content)
{
	if (!new)
		return ;
	*new = malloc(sizeof(t_list) * 1);
	if (!(*new))
		return ;
	// (*new)->index = 0;
	(*new)->value = content;
	(*new)->next = NULL;
	(*new)->prev = NULL;
}

void ft_lstdelone(t_list **node)
{
	t_list *new_head;

	if (!(*node))
		return ;
	if ((*node)->next == NULL || (*node)->prev == NULL)
	{
		free (*node);
		*node = NULL;
		return ;
	}
	new_head = (*node)->next;
	(*node)->next->prev = (*node)->prev;
	(*node)->prev->next = (*node)->next;
	free (*node);
	*node = new_head;
}

int ft_lstsize (t_list *head)
{
	size_t count;
	t_list *tmp = head;

	if (!head)
		return (0);
	count = 1;
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
