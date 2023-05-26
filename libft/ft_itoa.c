/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:53:50 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 15:04:43 by mayyamad         ###   ########.fr       */
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

char	*convert(long n, int flag, size_t len)
{
	char	buf;
	char	*str;
	int		i;

	i = 0;
	if (flag == 0)
		str = (char *)malloc(len + 1);
	if (flag == 1)
		str = (char *)malloc(len + 2);
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
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	count_len(int n)
{
	int	count;

	count = 0;
	while (n / 10)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	int		flag;
	char	*str;
	int		len;
	long	n1;

	n1 = n;
	flag = 0;
	len = count_len(n1);
	if (n1 == 0)
	{
		str = (char *)malloc(len + 1);
		*str = '0';
		return (str);
	}
	if (n1 < 0)
	{
		n1 = -n1;
		flag = 1;
	}
	if (flag == 0)
		str = (char *)malloc(len + 1);
	if (flag == 1)
		str = (char *)malloc(len + 2);
	if (str == NULL)
		return (NULL);
	str = convert(n1, flag, len);
	return (ft_reverse(str));
}
