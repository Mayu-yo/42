/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/28 10:27:43 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_all(char **ret, int count)
{
	while (count >= 0)
	{
		free(ret[count]);
		count--;
	}
	free(ret);
	return (NULL);
}

char	**null_terminate_array(char **ret, int i, int j, int flag)
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
			if (ret[i] == NULL)
				return (free_all(ret, i - 1));
		}
		else if (*s != c)
		{
			if (flag == 1)
				flag = 0;
			ret[i][j++] = *s;
		}
		s++;
	}
	return (null_terminate_array(ret, i, j, flag));
}

int count_word_len(const char *s, char c)
{
	int	count;
	
	count = 0;
	while (*s != c)
	{
		s++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		len;
	int		flag;
	int		word_len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	word_len = count_word_len(s, c);
	ret = (char **)malloc((len + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[0] = (char *)malloc((word_len + 1) * sizeof(char));
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
