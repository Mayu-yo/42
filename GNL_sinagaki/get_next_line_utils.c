/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:36:51 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/29 22:29:46 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (size != 0 && __LONG_LONG_MAX__ / size < count)
		return (NULL);
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = malloc(len_s1 + len_s2 + 1);
	if (dst == NULL)
		return (NULL);
	if (len_s1 + len_s2 == 0)
	{
		*dst = 0;
		return (dst);
	}
	ft_strlcpy(dst, s1, len_s1 + 1);
	ft_strlcpy(&dst[len_s1], s2, len_s2 + 1);
	free(s1);
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	if (dstsize <= 0)
	{
		while (src[i] != 0)
			i++;
		return (i);
	}
	while (src[i] != 0 && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (*str != 0)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == 0)
		return (str);
	return (0);
}
