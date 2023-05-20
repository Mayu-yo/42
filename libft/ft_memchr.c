/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:36:45 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:37:29 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (*p != (unsigned char)c)
	{
		if (*p == '\0' || n == 0)
			return (NULL);
		p++;
		n--;
	}
	return ((void *)p);
}

// #include <stdio.h>
// int main(){
// 	char *ret;
// 	ret = ft_memchr("asdfg",100,1);
// 	printf("%s",ret);
// 	return 0;
// }
