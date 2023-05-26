/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:49:19 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 21:50:22 by mayu             ###   ########.fr       */
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

// #include <stdio.h>
// int main()
// {
//     // char dest[20] = "CCCCC";
//     // char src[] = "AAAAA";
//     // int x = -1;
// 	char b[0xF] = "nyan !";
// 	unsigned int result = ft_strlcat(((void *)0), b, 2);
//     //unsigned int result = ft_strlcat(dest, src, x);
//     printf("自作 %u\n", result);
// 	unsigned int result1 = strlcat(((void *)0), b, 2);
// 	//unsigned int result1 = strlcat(dest, src, x);
//     printf("本物 %u\n", result1);
//     return(0);
// }
