/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:06:45 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/21 15:31:23 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

#include <stdio.h>
int main() {
	int ret = ft_strncmp("qwertyu", "qwe", -42);
	printf("%d", ret);
	return 0;
}