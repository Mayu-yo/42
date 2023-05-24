/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:36:45 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/24 22:33:00 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *s = calloc(30, sizeof(char));
// memcpy(s, "libft-test-tokyo", 17);
// memcpy(s + 20, "acdfg", 5);

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p;

	p = s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
		n--;
	}
	return NULL;
}

// #include <stdio.h>
// int main(){
// 	char *ret;
// 	//char *s = calloc(30, sizeof(char));
// 	char s[] = {0,1,2,3,4,5};
// 	//memcpy(s, 0, 0);
// 	//memcpy(s + 20, "acdfg", 5);
// 	ret = ft_memchr(s, 0, 0);
// 	printf("%s\n",ret);
// 	ret = memchr(s, 0, 0);
// 	printf("%s",ret);
// 	return 0;
// }
