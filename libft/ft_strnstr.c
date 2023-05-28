/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:24:15 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/28 14:25:13 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	n_len;
	size_t	h_len;
	size_t	i;

	if (h == NULL && len == 0)
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
