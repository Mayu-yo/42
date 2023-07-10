#include "push_swap.h"
//headerの整理
//エラーチェック、セグフォ探し
//norminette, makefile

static int ft_create_list(t_list **list, int argc, char **argv)
{
	t_list *new;

	new = NULL;
	ft_lstnew(list, ft_atoi(argv[argc - 2]), -1);
	if (!list)
		return (-1);
	if (argc == 2)
		return (0);
	while (argc > 2)
	{
		ft_lstnew(&new, ft_atoi(argv[argc - 3]), -1);
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
	if (argc < 2)
		return (0);
	if (argc == 2){
		arg_new = ft_split(argv[1], ' ');
		if (!arg_new)
			return (0);
		// argc = ft_count_arg(arg_new);
		argc = 0;
		while (arg_new[argc])
			argc++;
		argc++;
	}
	else
		arg_new = &argv[1];
	if (ft_arg_check(arg_new) == -1)
	{
		printf("Error\n");
		return (0);
	}
	if (ft_create_list(&list, argc, arg_new) == -1)
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
	while (argc - 1 > 0)
	{
		ft_lstdelone(&(list));
		argc--;
	}
	system("leaks -q push_swap");
	return (0);
}