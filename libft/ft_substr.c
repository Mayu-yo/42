/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:54:21 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 14:54:22 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int			i;
	char		*ret;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
	{
		ret = (char *)malloc(1);
		return (ret);
	}
	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	while (len != 0 && s[start + i] != '\0')
	{
		ret[i] = s[start + i];
		i++;
		len--;
	}
	ret[i] = '\0';
	return (ret);
}
