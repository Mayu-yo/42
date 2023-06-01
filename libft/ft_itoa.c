/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:53:50 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/01 18:42:06 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *str)
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

static char	*convert(long n, int flag, char *str)
{
	char	buf;
	int		i;

	i = 0;
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

static int	count_len(int n)
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

static char	*if_zero(char *str)
{
	str = (char *)malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		flag;
	char	*str;
	int		len;
	long	n_long;

	n_long = n;
	flag = 0;
	str = NULL;
	len = count_len(n_long);
	if (n_long == 0)
		return (if_zero(str));
	if (n_long < 0)
	{
		n_long = -n_long;
		flag = 1;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str = convert(n_long, flag, str);
	return (ft_reverse(str));
}
