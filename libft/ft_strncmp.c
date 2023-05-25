/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:06:45 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 15:33:30 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (ret != 0)
			return (ret);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main() {
// 	char *str = "libft-test-tokyo";
// 	int len = strlen(str);
// 	char *cmp2 = calloc(10, 1);
// 	strlcpy(cmp2, "libft", 10);
// 	//cmp2[5] = (-__SCHAR_MAX__-1);
// 	cmp2[5] = (-42);
// 	int ret = ft_strncmp(str, cmp2, len);
// 	printf("%d\n", ret);
// 	ret = strncmp(str, cmp2, len);
// 	printf("%d", ret);
// 	return 0;
// }