#include "push_swap.h" 
//arg check 関数分ける 引数が""で囲まれていた時の対処
//headerの整理
//関数にstaticつける
//エラーチェック、セグフォ探し
//norminette
//isintの処理どこまでやってるか確認すること

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

int ft_is_sorted(t_list *list, int argc);
int ft_is_duplicated(int argc, char **argv);
int ft_is_integer(int argc, char **argv);

static int ft_arg_check(int argc, char **argv)
{
	if (ft_is_integer(argc, argv) == -1)
		return (-1);
	if (ft_is_duplicated(argc, argv) == -1)
		return (-1);
	return (0);
}

int ft_is_sorted(t_list *list, int argc)
{
	while (list->next && argc > 2)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
		argc--;
	}
	return (-1);
}

int ft_is_duplicated(int argc, char **argv)
{
	int i;
	int j;

	j = 1;
	while (j < argc - 1)
	{
		i = 1 + j;
		while (argv[i])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int ft_is_integer(int argc, char **argv)
{
	int i;
	int j;
	long val;

	i = 1;
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
		val = ft_atoi(argv[i]);
		if (val < INT_MIN || INT_MAX < val)
			return (-1);
		i++;
	}
	return (0);
}

void ft_print_list(t_list *head, int argc);

int main (int argc, char **argv)
{
	t_list *list;
	t_list *stack_b;

	list = NULL;
	stack_b = NULL;

	// argc = 3;
	// argv[0] = "./push_swap";
	// argv[1] = "2";
	// argv[2] = "5";
	// argv[3] = NULL;
	// argv[4] = NULL;

	if (argc < 3)
		return (0);
	if (ft_arg_check(argc, argv) == -1)
	{
		printf("Error\n");
		return (0);
	}
	if (ft_create_list(&list, argc, argv) == -1)
		return (0);
	ft_assign_index(&list, argc);
	// ft_print_list(list, argc);
	// if (argc - 1 == 1)
	// 	return (0);
	if (ft_lstsize(list) != argc - 1)
		return (0);
	if (ft_is_sorted(list, argc) == -1)
		return (0);
	if (argc - 1 == 2)
		ft_swap(list);
	else if (argc - 1 == 3)
		ft_sort_three(&list);
	else if (4 <= argc - 1 && argc - 1 <= 5)
		ft_sort_five_or_less(&list, &stack_b, argc);
	else if (6 <= argc - 1)
		ft_sort(&list, &stack_b, argc);
	// ft_print_list(list, argc);
	while (argc - 1 > 0)
	{
		ft_lstdelone(&(list));
		argc--;
	}
	system("leaks -q push_swap");
	return (0);
}

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
