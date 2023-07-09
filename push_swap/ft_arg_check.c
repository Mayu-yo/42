#include "push_swap.h"

int ft_arg_check(int argc, char **argv)
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

// int ft_doublequoted_arguments(int argc, char **argv)
// {
// 	int i;
// 	char **str;

// 	i = 0;
// 	str = NULL;
// 	if (argv[1][0] == '"' && argv[1][ft_strlen(argv[1]) - 1] == '"')
// 	{
// 		str = ft_split(argv[1], '"');
// 		str = ft_split(str[0], ' ');
// 		if (!str)
// 			return (-1);
// 	}
// 	while (str[i])
// 		i++;
// 	if (!ft_arg_check(i + 1, str))
// 		return (-1);
// 	argv = str;
// 	return (0);
// }