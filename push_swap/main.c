#include "push_swap.h"

int pa(t_list **a, t_list **b)
{
	t_list *new;

	if (!b || !(*b))
		return (-1);
	if (!(*a))
	{
		ft_lstnew(a, (*b)->value, (*b)->index);
		if (!a)
			return (-1);
	}
	else
	{
		ft_lstnew(&new, (*b)->value, (*b)->index);
		if (!new)
			return (-1);
		ft_addfront(a, new);
	}
	ft_lstdelone(b);
	ft_putendl_fd("pa", 1);
	return (0);
}



void ft_lstdelone(t_list **node)//ぐちゃった
{
	t_list *prev_node;
	t_list *next_node;

	if (!(*node))
		return ;
	prev_node = (*node)->prev;
	next_node = (*node)->next;
	// printf("delone: %p\n", *node);
	free(*node);
	if (next_node->next != next_node)
	{
		prev_node->next = next_node;
		next_node->prev = prev_node;
		*node = next_node;
	}
	else
		*node = NULL;
}


void ft_sort_six_or_less(t_list **stack_a, t_list **stack_b, int argc)
{
	int i;

	i = 0;
	while (i < argc - 4)
	{
		if ((*stack_a)->index == i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}


static int ft_create_list(t_list **list, int argc, char **argv)
{
	t_list *new;

	new = NULL;
	ft_lstnew(list, ft_atoi(argv[argc - 1]), -1);
	if (!list)
		return (-1);
	if (argc == 2)
		return (0);
	while (argc > 2)
	{
		ft_lstnew(&new, ft_atoi(argv[argc - 2]), -1);
		if (!new)
			return (-1);
		ft_addfront(list, new);
		argc--;
	}
	return (0);
}

static int ft_arg_check(int argc, char **argv)
{
	int i;
	int j;
	size_t flag;
	long value[argc - 1];

	i = 1;
	//is integer
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || j > 13)//INT_MAXが処理系依存ならちゃんと割ろう
				return (-1);
			j++;
		}
		value[i - 1] = ft_atoi(argv[i]);
		if (value[i - 1] < INT_MIN || INT_MAX < value[i - 1])
			return (-1);
		i++;
	}
	//duplicate or sorted
	j = 0;
	flag = 0;
	while (j < argc - 2)
	{
		i = 1 + j;
		if (value[j] > value[j + 1])
			flag = 1;
		while (argv[i + 1])
		{
			if (value[j] == ft_atoi(argv[i + 1]))
				return (-1);
			i++;
		}
		j++;
		if (j + 2 == argc && flag == 0)
			return (1);
	}
	return (0);
}

void ft_print_list(t_list *head, int argc);

int main (int argc ,char** argv)
{
	int i;
	t_list *list;
	t_list *stack_b;

	list = NULL;
	stack_b = NULL;
	argc = 6;
	argv[1]	= "3";
	argv[2] = "2";
	argv[3] = "1";
	argv[4] = "5";
	argv[5] = "4";
	argv[argc] = NULL;

	if (argc < 2)
		return (0);
	i = ft_arg_check(argc, argv);
	if (i == -1)
	{
		printf("Error\n");
		return (0);
	} else if (i == 1)
	{
		printf("already sorted\n");
		return (0);
	}
	if (ft_create_list(&list, argc, argv) == -1)
		return (0);
	ft_assign_index(&list, argc);
	ft_print_list(list, argc);
	if (ft_lstsize(list) != argc - 1)
		return (0);
	if (argc - 1 == 1)
		return (0);
	if (argc - 1 == 2)
		ft_swap(list);
	else if (argc - 1 == 3)
		ft_sort_three(&list);
	else if (4 <= argc - 1 && argc - 1 <= 6)
		ft_sort_six_or_less(&list, &stack_b, argc);
	// else if (7 <= argc - 1 && argc - 1 <= 100)
	ft_print_list(list, argc);
	while (argc - 1 > 0)
	{
		ft_lstdelone(&(list));
		argc--;
	}
	system("leaks -q a.out");
	return (0);
}

/*--------------------------------------------------------*/

void ft_print_list(t_list *head, int argc)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }
    printf("List contents: ");
    while (argc > 1)
    {
        printf("%d", head->value);
		printf("[%d] ", head->index);
        head = head->next;
		argc--;
    }
    printf("\n");
}