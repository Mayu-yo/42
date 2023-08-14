/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:11:02 by mayu              #+#    #+#             */
/*   Updated: 2023/08/15 00:37:37 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	error_message(void)
{
	ft_putendl_fd("invalid input", 2);
	exit (0);
}

double	karifunc(size_t i, double ret, char *num)
{
	size_t	j;

	j = 1;
	while ('0' <= num[i] && num[i] <= '9')
		ret = ret + ((num[i++] - '0') * pow((0.1), j++));
	return (ret);
}

double	ft_atof(char *num)
{
	int		minus_flag;
	size_t	i;
	double	ret;

	minus_flag = 1;
	i = 0;
	ret = 0;
	if (num[i] == '-')
	{
		minus_flag = -1;
		i++;
	}
	while ('0' <= num[i] && num[i] <= '9')
		ret = ret * 10 + num[i++] - '0';
	if (num[i] == '.' && i > 0)
		karifunc(i + 1, ret, num);
	// if (num[i] != '\0')
	// 	error_message();
	return (ret * minus_flag);
}
