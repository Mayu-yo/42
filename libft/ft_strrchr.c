/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:53:45 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 15:03:48 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*p;
	const unsigned char	*ret;

	p = (const unsigned char *)s;
	ret = NULL;
	while (*p != '\0')
	{
		if (*p == (unsigned char)c)
			ret = p;
		p++;
	}
	if (c == '\0')
		return ((char *)p);
	return ((char *)ret);
}
