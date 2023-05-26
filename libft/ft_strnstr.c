/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:19:05 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 21:39:25 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t n_len;
	size_t h_len;
	size_t i;

	if (h == NULL)
		return (NULL);
	n_len = ft_strlen(n);
	h_len = ft_strlen(h);
	if (n_len == 0)
		return ((char *)h);
	if (len < n_len || h_len < n_len)
		return (NULL);
	i = 0;
	while (i <= h_len - n_len && i <= len - n_len)
	{
		if (ft_strncmp(h + i, n, n_len) == 0)
			return ((char *)(h + i));
		i++;
	}

	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	char a[] = "qwert";
// 	char b[] = "wr";
// 	char *ret;

// 	ret = ft_strnstr(NULL, "1", 0);
// 	write(1, ret, sizeof(ret));
// 	ret = strnstr(NULL, "1", 0);
// 	write(1, ret, sizeof(ret));
// 	return 0;
// }
