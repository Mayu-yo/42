/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:38:47 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/23 10:58:16 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	if(n == 0)
		return 0;
	while (*p1 == *p2 && (n-1) != 0)
	{
		p1++;
		p2++;
		n--;
	}
	return (*p1 - *p2);
}

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_memcmp("qwert", "qwertadf", 6);
// 	printf("%d",ret);
// 	return 0;
// }
