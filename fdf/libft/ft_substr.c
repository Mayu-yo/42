/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:54:21 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/30 23:18:03 by mayu             ###   ########.fr       */
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
		ret = ft_calloc(1, 1);
		return (ret);
	}
	if (len > ft_strlen(s))
		ret = (char *)malloc(ft_strlen(s));
	else
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
