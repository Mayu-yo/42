/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:53:50 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/21 14:08:56 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str)
{
	size_t	str_len;
	size_t	i;
	char	buf;

	i = 0;
	str_len = ft_strlen(str);
	while (str_len / 2 > i)
	{
		buf = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = buf;
		i++;
	}
	str[str_len] = '\0';
	return (str);
}

char	*convert(int n, int flag)
{
	char	buf;
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(12);
	if (str == NULL)
		return (NULL);
	while (n != 0)
	{
		buf = n % 10;
		str[i] = buf + '0';
		n /= 10;
		i++;
	}
	if (flag == 1)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		flag;
	char	*str;

	flag = 0;
	str = (char *)malloc(12);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		n = -n;
		flag = 1;
	}
	str = convert(n, flag);
	return (ft_reverse(str));
}

// #include <stdio.h>
// int main() {
// 	char *str;

// 	str = (char *)malloc(12);
// 	if (str == NULL)
// 		return 0;
// 	str = ft_itoa(-234567);
// 	printf("%s", str);
// 	return 0;
// }
