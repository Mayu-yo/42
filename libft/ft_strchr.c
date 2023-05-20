/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:56:49 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:56:51 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	while (*p != (unsigned char)c)
	{
		if (*p == '\0' && c != '\0')
			return (NULL);
		p++;
	}
	return ((char *)p);
}

// int main(){
// 	char c[] = "asdfg";
// 	char *ret;
// 	ret = ft_strchr(c, 100);
// 	write(1, ret, sizeof(c));
// 	return 0;
// }
