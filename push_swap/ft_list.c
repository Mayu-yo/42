#include "push_swap.h"

void ft_lstnew(t_list **new, int content, int num)
{
	*new = malloc(sizeof(t_list) * 1);
	if (!(*new))
		return ;
	(*new)->index = num;
	(*new)->value = content;
	(*new)->next = (*new);
	(*new)->prev = (*new);
}

void ft_lstdelone(t_list **node)
{
	t_list *prev_node;
	t_list *next_node;

	if (!(*node))
		return ;
	prev_node = (*node)->prev;
	next_node = (*node)->next;
	if (next_node == (*node))
	{
		free(*node);
		*node = NULL;
		return ;
	}
	prev_node->next = next_node;
	next_node->prev = prev_node;
	free(*node);
	*node = next_node;
}

int ft_lstsize (t_list *head)
{
	size_t count;
	t_list *tmp;

	if (!head)
		return (0);
	count = 1;
	tmp = head;
	if (tmp->next == tmp)
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
	if ((*head)->next == (*head))
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
