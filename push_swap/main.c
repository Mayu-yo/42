#include "push_swap.h" //statictuketenaiya

void ft_temporary_relocation(t_list **stack_a, t_list **stack_b, int i)
{
	while (i > 1)
	{
		ra(stack_a);
		i--;
	}
	pa(stack_a, stack_b);
	while ((*stack_a)->index > (*stack_a)->prev->index)
		rra(stack_a);
}

void ft_return(t_list **stack_a, t_list **stack_b, int lstsize)
{
	int distance;
	int i;

	i = 1;
	lstsize = lstsize - 1;
	while (*stack_b)
	{
		distance = count_distance(*stack_b, lstsize);
		while ((*stack_b)->index != lstsize)
		{
			if ((*stack_b)->index == lstsize - i)
			{
				pa(stack_a, stack_b);
				i++;
			}
			else
			{
				if (distance <= lstsize / 2)
					rb(stack_b);
				else
					rrb(stack_b);
			}
		}
		if (i > 1)
		{
			ft_temporary_relocation(stack_a, stack_b, i);
			lstsize = lstsize - i + 1;
		}
		else
			pa(stack_a, stack_b);
		i = 1;
		lstsize--;
	}
}
//--------------------------------------------------------

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
	// argc = 21;
	// argv[0] = "push_swap";
	// argv[1] = "13";
	// argv[2] = "31";
	// argv[3] = "2";
	// argv[4] = "1";
	// argv[5] = "5";
	// argv[6] = "4";
	// argv[7] = "3";
	// argv[8] = "6";
	// argv[9] = "76";
	// argv[10] = "35";
	// argv[11] = "23";
	// argv[12] = "12";
	// argv[13] = "11";
	// argv[14] = "66";
	// argv[15] = "77";
	// argv[16] = "88";
	// argv[17] = "48";
	// argv[18] = "63";
	// argv[19] = "99";
	// argv[20] = "100";
	// argv[21] = NULL;
	if (argc < 2)
		return (0);
	i = ft_arg_check(argc, argv);
	if (i == -1)
	{
		// printf("Error\n");
		return (0);
	} else if (i == 1)
	{
		// printf("already sorted\n");
		return (0);
	}
	if (ft_create_list(&list, argc, argv) == -1)
		return (0);
	ft_assign_index(&list, argc);
	// ft_print_list(list, argc);
	if (ft_lstsize(list) != argc - 1)
		return (0);
	if (argc - 1 == 1)
		return (0);
	if (argc - 1 == 2)
		ft_swap(list);
	else if (argc - 1 == 3)
		ft_sort_three(&list);
	else if (4 <= argc - 1 && argc - 1 <= 6)
		ft_sort_six_or_less	(&list, &stack_b, argc);
	// else if (7 <= argc - 1 && argc - 1 <= 500)
	else if (7 <= argc - 1)
		ft_sort(&list, &stack_b, argc);
	// ft_print_list(list, argc);
	// ft_print_list(stack_b, argc);
	while (argc - 1 > 0)
	{
		ft_lstdelone(&(list));
		argc--;
	}
	// system("leaks -q push_swap");
	return (0);
}

/*--------------------------------------------------------*/

// void ft_print_list(t_list *head, int argc)
// {
//     if (!head)
//     {
//         printf("List is empty.\n");
//         return;
//     }
//     printf("List contents: ");
//     while (argc > 1)
//     {
//         printf("%d", head->value);
// 		printf("[%d] ", head->index);
//         head = head->next;
// 		argc--;
//     }
//     printf("\n");
// }
