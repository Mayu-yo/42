#include "push_swap.h"

//スタックをプリントする関数

static int ft_create_list(t_list **list, int argc, char **argv)
{
	t_list *new;

	new = NULL;
	ft_lstnew(&new, ft_atoi(argv[argc - 1]));
	if (!new)
		return (-1);
	*list = malloc(sizeof(t_list) * argc - 1);
	*list = new;
	if (argc == 2)
		return (0);
	while (argc > 2)
	{
		ft_lstnew(&new, ft_atoi(argv[argc - 2]));
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

	list = NULL;
	// argc = 7;
	// argv[1]	= "-2147483648";
	// argv[2] = "2";
	// argv[3] = "3";
	// argv[4] = "5";
	// argv[5] = "6";
	// argv[6] = "7";
	// argv[argc] = NULL;

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
	ft_create_list(&list, argc, argv);
	ft_print_list(list, argc);
	if (ft_lstsize(list) != argc - 1)//このチェックいる？
		return (0);
	if (argc - 1 == 2)
		ft_swap(list);
	else if (argc - 1 == 3)
		ft_sort_three(&list);
	else if (4 <= argc - 1 && argc - 1 <= 6)
		ft_sort_six_or_less(list, argc);
	// else if (7 <= argc - 1 && argc - 1 <= 100)
	ft_print_list(list, argc);
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
    while (argc > 1)//循環してるか確かめるために一個多く書いてるよん
    {
        printf("%d ", head->value);
        head = head->next;
		argc--;
    }
    printf("\n");
}

// int main(int argc, char **argv)
// {
// 	t_list *list;

// 	list = NULL;

// 	// argc = 4;
// 	// argv[1]	= "1";
// 	// argv[2] = "2";
// 	// argv[3] = "3";
//     if (argc < 2)
//     {
//         printf("Usage: ./test <num1> <num2> ...\n");
//         return 1;
//     }

//     if (ft_create_list(&list, argc, argv) == 0)
//     {
//         printf("List creation successful!\n");
//         ft_print_list(list, argc); // 作成したリストの表示
//     }
//     else
//     {
//         printf("List creation failed!\n");
//     }

//     return 0;
// }