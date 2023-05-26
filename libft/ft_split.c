/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 14:29:49 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**return_chr(char **ret, int i, int j, int flag)
{
	if (flag == 0)
		ret[i++][j] = '\0';
	ret[i] = NULL;
	return (ret);
}

char	**ft_split2(char const *s, char c, char **ret, int flag)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s == c && flag == 0)
		{
			ret[i++][j] = '\0';
			flag = 1;
			j = 0;
			ret[i] = (char *)malloc(ft_strlen(s));
		}
		else if (*s != c)
		{
			if (flag == 1)
				flag = 0;
			ret[i][j++] = *s;
		}
		s++;
	}
	return (return_chr(ret, i, j, flag));
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		len;
	int		flag;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ret = (char **)malloc((len + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[0] = (char *)malloc((len + 1) * sizeof(char));
	if (ret[0] == NULL)
	{
		free(ret);
		return (NULL);
	}
	flag = 0;
	if (s[0] == c || s[0] == '\0')
		flag = 1;
	ret = ft_split2(s, c, ret, flag);
	return (ret);
}
