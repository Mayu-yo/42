/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:48:21 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/05 18:25:15 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	unsigned char		*d;
// 	const unsigned char	*s;

// 	d = dst;
// 	s = src;
// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	while (n > 0)
// 	{
// 		*d = *s;
// 		d++;
// 		s++;
// 		n--;
// 	}
// 	return (dst);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char		*s;
// 	size_t		len1;
// 	size_t		len2;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	s = (char *)malloc(len1 + len2 + 1);
// 	if (s == NULL)
// 		return (NULL);
// 	ft_memcpy(s, s1, len1);
// 	ft_memcpy(s + len1, s2, len2 + 1);
// 	return (s);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	const unsigned char	*p;

// 	p = (const unsigned char *)s;
// 	while (*p != (unsigned char)c)
// 	{
// 		if (*p == '\0' && c != '\0')
// 			return (NULL);
// 		p++;
// 	}
// 	return ((char *)p);
// }

char	*new_func(const char *s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	const unsigned char	*p;
	char *ret;

	p = (const unsigned char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(len1 + len2 + 1);
	if (ret == NULL)
		return (NULL);
	while (*s2 != '\n')
	{
		if (*s2 == '\0')
			return (NULL);
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (s1);
}