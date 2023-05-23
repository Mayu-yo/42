/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:29 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/23 12:34:31 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (str[i] == '0')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10;
		num += str[i] - '0';
		i++;
	}
	return (num * fugou);
}

#include <stdio.h>
int main()
{
	char str[] = "-1j84467";
	int num;
	num = ft_atoi(str);
	printf("%d\n", num);
	num = atoi(str);
	printf("%d", num);
	return 0;
}