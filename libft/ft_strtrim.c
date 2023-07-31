/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:54:07 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/01 18:35:55 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim_char(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	while (is_trim_char(s1[start], set))
		start++;
	while (len > start && is_trim_char(s1[len - 1], set))
		len--;
	ret = (char *)malloc(len - start + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1 + start, len - start + 1);
	return (ret);
}
