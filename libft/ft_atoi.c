/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:29 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/28 09:41:14 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_space(const char *str)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		minus;

	minus = 1;
	i = skip_space(str);
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (num > ((LONG_MAX - (str[i] - '0')) / 10) && minus == 1)
			return ((int)(LONG_MAX));
		if (num - (1 / 10) > (LONG_MAX - (str[i] - '0')) / 10 && minus == -1)
			return ((int)(LONG_MIN));
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * minus);
}
