/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:36:45 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/23 10:52:55 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// char *s = calloc(30, sizeof(char));
	// memcpy(s, "libft-test-tokyo", 17);
	// memcpy(s + 20, "acdfg", 5);

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (*p != (unsigned char)c)
	{
		if (n == 0)
			return (NULL);
		p++;
		n--;
	}
	return ((void *)p);
}

// #include <stdio.h>
// int main(){
// 	char *ret;
// 	char *s = calloc(30, sizeof(char));
// 	memcpy(s, "libft-test-tokyo", 17);
// 	memcpy(s + 20, "acdfg", 5);
// 	ret = ft_memchr(s, 'a', 30);
// 	printf("%s",ret);
// 	ret = memchr(s, 'a', 30);
// 	printf("%s",ret);
// 	return 0;
// }
