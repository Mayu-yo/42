/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:06:43 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/19 16:55:05 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_reverse(char *str, size_t str_len)
{
	size_t	i;
	char	buf;

	i = 0;
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

static char	*convert(unsigned long n, char *str, int uporlow)
{
	char	buf;
	int		i;
	char	ch;

	i = 0;
	if (uporlow == 0)
		ch = 'a';
	else
		ch = 'A';
	if (str == NULL)
		return (NULL);
	while (n != 0)
	{
		buf = n % 16;
		if (buf < 10)
			str[i] = buf + '0';
		else
			str[i] = buf + ch - 10;
		n /= 16;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*convert_hex(unsigned long n, int uporlow,
	size_t hex_len, char *str)
{
	if (n == 0)
	{
		str = malloc(hex_len + 1);
		*str = '0';
		return (str);
	}
	str = malloc(hex_len + 1);
	if (str == NULL)
		return (NULL);
	str = convert(n, str, uporlow);
	return (ft_reverse(str, hex_len));
}

int	ft_puthex(unsigned long n, int uporlow)
{
	char	*ret;
	size_t	hex_len;

	ret = NULL;
	if (n < 0)
		return (-1);
	hex_len = ft_count_len(n, 16);
	ret = convert_hex(n, uporlow, hex_len, ret);
	write(1, ret, hex_len);
	free (ret);
	return (hex_len);
}
