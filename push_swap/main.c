/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:50:07 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/14 11:52:26 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_create_list(t_list **list, int argc, char **argv)
{
	t_list	*new;

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

void	ft_dispatch(t_list *list, int argc)
{
	t_list	*stack_b;

	stack_b = NULL;
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
}

int	ft_execute_sorting(char **arg_new, t_list *list, int argc)
{
	if (ft_arg_check(arg_new) == -1)
	{
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	if (ft_create_list(&list, argc, arg_new) == -1)
		return (-1);
	ft_assign_index(&list, argc);
	if (ft_is_sorted(list, argc) == -1)
		return (-1);
	ft_dispatch(list, argc);
	return (0);
}

static void ft_free(char **list, int argc, int flag)
{
	int i;
	
	i = 0;
	if (flag == 1)
	{
		while (argc > 1)
		{
			free(list[i]);
			i++;
			argc--;
		}
		free(list);
	}
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	int flag;
	char	**arg_new;
	t_list	*list;

	flag = 0;
	list = NULL;
	arg_new = NULL;
	if (ft_is_integer(argv) == -1)
		return (-1);
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		arg_new = ft_split(argv[1], ' ');
		if (!arg_new)
			return (0);
		while (arg_new[argc - 2])
			argc++;
		argc--;
		flag = 1;
	}
	else
		arg_new = &argv[1];
	ft_execute_sorting(arg_new, list, argc);
	ft_free(arg_new, argc, flag);
	return (0);
}
