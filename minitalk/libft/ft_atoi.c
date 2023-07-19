/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:29 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/19 16:33:46 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_pid(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		num = num * 10 + str[i] - '0';
		if (num > ((INT_MAX - (str[i] - '0')) / 10))
			return (-1);
		i++;
	}
	return (num);
}
