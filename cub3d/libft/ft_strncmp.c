/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:06:45 by mayyamad          #+#    #+#             */
/*   Updated: 2024/10/06 11:10:30 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				ret;

	i = 0;
	ret = 0;
	if (!s1 || !s2)
		return (-1);
	// if (ft_strlen(s1) != n)
	// 	return (-1);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (ret != 0)
			return (ret);
		i++;
	}
	return (0);
}
