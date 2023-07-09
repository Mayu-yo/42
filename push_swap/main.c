#include "push_swap.h" 
//arg check 関数分ける 引数が""で囲まれていた時の対処
//headerの整理
//関数にstaticつける
//エラーチェック、セグフォ探し
//norminette
//isintの処理どこまでやってるか確認すること
//libft合体させる
void ft_print_list(t_list *head, int argc);

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

int main (int argc, char **argv)
{
	char **arg_new;
	t_list *list;
	t_list *stack_b;

	list = NULL;
	stack_b = NULL;

	argc = 2;
	argv[0] = "./push_swap";
	argv[1] = "0 3 7 2";
	argv[2] = NULL;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argc = 0;
		arg_new = ft_split(argv[1], ' ');
		while (argv[argc])
			argc++;
		argc++;
	}
	if (ft_arg_check(argc, argv) == -1)
	{
		printf("Error\n");
		return (0);
	}
	if (ft_create_list(&list, argc, argv) == -1)
		return (0);
	ft_assign_index(&list, argc);
	if (ft_lstsize(list) != argc - 1)
		return (0);
	if (ft_is_sorted(list, argc) == -1)
		return (0);
	if (argc - 1 == 2)
		sa(&list);
	else if (argc - 1 == 3)
		ft_sort_three(&list);
	else if (4 <= argc - 1 && argc - 1 <= 5)
		ft_sort_five_or_less (&list, &stack_b, argc);
	else if (6 <= argc - 1)
		ft_sort(&list, &stack_b, argc);
	// ft_print_list(list, argc);
	while (argc - 1 > 0)
	{
		ft_lstdelone(&(list));
		argc--;
	}
	// system("leaks -q push_swap");
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
