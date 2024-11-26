/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:58:36 by mayyamad          #+#    #+#             */
/*   Updated: 2024/11/04 22:23:19 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dst;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
