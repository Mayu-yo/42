/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:48:21 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/24 13:54:03 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	size_t		len1;
	size_t		len2;

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (s2 == NULL)
		return (NULL);
	len2 = ft_strlen(s2);
	s = (char *)malloc(len1 + len2 + 1);
	if (s == NULL)
		return (NULL);
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2 + 1);
	free((void *)s1);
	return (s);
}