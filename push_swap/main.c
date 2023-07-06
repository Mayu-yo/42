#include "push_swap.h" //statictuketenaiya

// void ft_sort2(t_list **stack_a, t_list **stack_b, int argc)//copilot
// {
// 	int i;
// 	int j;
// 	int count;
// 	int distance;
// 	int flag;

// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		j = 0;
// 		flag = 0;
// 		while (j < argc - 1)
// 		{
// 			if ((*stack_a)->index == i)
// 			{
// 				pb(stack_a, stack_b);
// 				i++;
// 				flag = 1;
// 				break;
// 			}
// 			else
// 				ra(stack_a);
// 			j++;
// 		}
// 		if (flag == 0)
// 		{
// 			count = 0;
// 			distance = 0;
// 			while (count < argc - 1)
// 			{
// 				if ((*stack_a)->index == i)
// 				{
// 					pb(stack_a, stack_b);
// 					i++;
// 					break;
// 				}
// 				else
// 				{
// 					ra(stack_a);
// 					distance++;
// 				}
// 				count++;
// 			}
// 			count = 0;
// 			while (count < distance)
// 			{
// 				rra(stack_a);
// 				count++;
// 			}
// 		}
// 	}
// 	while(*stack_b)
// 		pa(stack_a, stack_b);
// }

//--------------------------------------------------------------------
//quick sort

void ft_return(t_list **stack_a, t_list **stack_b, int lstsize);
size_t count_distance(t_list *stack_a, int i);

void ft_sort(t_list **stack_a, t_list **stack_b, int stack_size) {
	int num;
	int count;

	num = 20;
	count = 0;
	stack_size = stack_size - 1;//
	while (count < num && *stack_a)
	{
		if ((*stack_a)->index < num)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
	while (count < (num + num * 2) && *stack_a)
	{
		if ((*stack_a)->index < (num * 2))
		{
			pb(stack_a, stack_b);
			count++;
		}
		else if ((*stack_a)->index < (num + num * 2))
		{
			pb(stack_a, stack_b);
			rrb(stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
	ft_return(stack_a, stack_b, stack_size);
}

// void ft_split_array(t_list **stack_b, int stack_size)
// {
// 	int pibot;
// 	int lst_size;

// 	pibot = stack_size/2
// 	lst_size = ft_lstsize(stack_b);
// 	while (stack_b->index < pibot)
// 	{
// 		if (lst_size == 1)
// 			pa(stack_a, stack_b);
// 		else
// 			ft_split_array(stack_b, )
// 	}
// }

// void ft_return(t_list **stack_a, t_list stack_b)
// {
// 	while (*stack_b)
// 	{
// 		if ((*stack_b)->index < (*stack_b)->prev->index)
// 			rrb(stack_b);
// 		else
// 			pa(stack_a, stack_b);
// 	}
// }

//--------------------------------------------------------
//モッティソート

void ft_return(t_list **stack_a, t_list **stack_b, int lstsize)
{
	//lstsize は距離を測るためにスタックの大きさが欲しいから
	//argcは返す対象を確認するために
	int i;
	int distance;

	i = lstsize - 1;
	while (i > 0)
	{
		distance = count_distance(*stack_b, i);
		if (distance < lstsize / 2)
		{
			while ((*stack_b)->index == i)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index == i)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		i--;
	}
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
	// argc = 8;
	// argv[1] = "1";
	// argv[2] = "3";
	// argv[3] = "2";
	// argv[4] = "5";
	// argv[5] = "4";
	// argv[6] = "6";
	// argv[7] = "7";
	// argv[8] = NULL;

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
		ft_sort_six_or_less	(&list, &stack_b, argc);
	else if (7 <= argc - 1 && argc - 1 <= 100)
	{
		// ft_sort2(&list, &stack_b, argc);
		ft_sort(&list, &stack_b, argc);
	}
	ft_print_list(list, argc);
	ft_print_list(stack_b, argc);
	while (argc - 1 > 0)
	{
		ft_lstdelone(&(list));
		argc--;
	}
	// system("leaks -q push_swap");
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
