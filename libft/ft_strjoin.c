/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:48:21 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/21 14:48:41 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	s = (char *)malloc(len + 1);
	if (s == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

// #include <stdio.h>
// int main(){
// 	char *ret;
// 	ret = ft_strjoin("qwert","asdfg");
// 	printf("%s",ret);
// 	return 0;
// }
