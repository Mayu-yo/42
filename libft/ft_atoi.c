/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:29 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:17:02 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// int main()
// {
// 	char str[] = "-1234j234";
// 	int num;
// 	num = ft_atoi(str);
// 	printf("%d", num);
// 	return 0;
// }

int	kuhaku(const char *str)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	fugou;

	fugou = 1;
	i = kuhaku(str);
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			fugou *= -1;
			i++;
	}
	if ('0' >= str[i] && str[i] <= '9')
		return (num);
	while (str[i] >= '0' && '9' >= str[i])
	{
		num = num * 10;
		num += str[i] - '0';
		i++;
	}
	num = num * fugou;
	return (num);
}
