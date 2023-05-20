/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:58:36 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:58:40 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dst;

	len = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (NULL);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}

// #include <stdio.h>
// char *ft_strdup(const char *s);
// int main() {
//     const char* original = "Hello, World!";
//     char* duplicate = ft_strdup(original);

//     if (duplicate != NULL) {
//         printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);
//         free(duplicate);  // メモリの解放
//     }

//     return 0;
// }
