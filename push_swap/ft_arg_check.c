/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:45:53 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 12:45:54 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_check(char **argv)
{
	if (ft_is_integer(argv) == -1)
		return (-1);
	if (ft_is_duplicated(argv) == -1)
		return (-1);
	return (0);
}

int	ft_is_sorted(t_list *list, int argc)
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

int	ft_is_duplicated(char **argv)
{
	int	i;
	int	j;

	j = 0;
	while (argv[j])
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

int	ft_is_integer(char **argv)
{
	int		i;
	int		j;
	long	val;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || j > (INT_MAX / 10))
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
