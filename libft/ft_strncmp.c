/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:06:45 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/22 12:09:10 by mayyamad         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		ret = (unsigned int)s1[i] - (unsigned int)s2[i];
		if (ret != 0)
			return (ret);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main() {
// 	char *str = "libft-test-tokyo";
// 	int len = ft_strlen(str);
// 	char *cmp2 = calloc(10, 1);
// 	cmp2[5] = (-__SCHAR_MAX__-1);
// 	cmp2[5] = (-42);
// 	int ret = ft_strncmp(str, cmp2, len);
// 	printf("%d\n", ret);
// 	ret = strncmp(str, cmp2, len);
// 	printf("%d", ret);
// 	return 0;
// }