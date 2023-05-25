/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:58:36 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 11:20:20 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*str != '\0')
// 	{
// 		str++;
// 		i++;
// 	}
// 	return (i);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
//     size_t	srclen = 0;
//     size_t	i;

//     while (src[srclen] != '\0')
//         srclen++;
//     if (dstsize == 0)
//         return (srclen);
//     i = 0;
//     while (i < dstsize - 1 && src[i] != '\0')
//     {
//         dst[i] = src[i];
//         i++;
//     }
//     dst[i] = '\0';
//     return (srclen);
// }

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}

// #include <stdio.h>
// int main() {
//     const char* original = "";
//     char* duplicate = ft_strdup(original);
//         printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);
//         free(duplicate);  // メモリの解放
// 	 	duplicate = strdup(original);
// 		printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);
//         free(duplicate);  // メモリの解放
//     return 0;
// }
