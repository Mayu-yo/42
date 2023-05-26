/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:49:19 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 14:30:42 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

unsigned int	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	dst_len;
	unsigned int	total_len;
	unsigned int	copy_len;

	src_len = ft_strlen(src);
	if (dst == NULL)
		return (src_len);
	dst_len = ft_strlen(dst);
	total_len = dst_len + src_len;
	if (size <= dst_len)
		return (src_len + size);
	copy_len = size - dst_len - 1;
	ft_strncat(dst + dst_len, src, copy_len);
	dst[size - 1] = '\0';
	return (total_len);
}
