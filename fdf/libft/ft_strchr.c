/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:56:49 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/24 13:54:17 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*p;

	if (!s)
		return (NULL);
	p = (const unsigned char *)s;
	while (*p != (unsigned char)c)
	{
		if (*p == '\0' && c != '\0')
			return (NULL);
		p++;
	}
	return ((char *)p);
}