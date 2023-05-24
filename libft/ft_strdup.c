/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:58:36 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/24 22:42:36 by mayyamad         ###   ########.fr       */
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
	{
		dst = (char *)malloc(1);
		return (dst);
	}
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}

#include <stdio.h>
int main() {
    const char* original = "";
    char* duplicate = ft_strdup(original);

        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);  // メモリの解放
    
	 	duplicate = strdup(original);
		printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);  // メモリの解放

    return 0;
}
