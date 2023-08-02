/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/08 16:05:49 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **ret, int count)
{
	while (count >= 0)
	{
		free(ret[count]);
		count--;
	}
	free(ret);
	return (NULL);
}

static size_t	count_words(const char *str, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') && str[i] != c)
			len++;
		i++;
	}
	return (len);
}

static size_t	ft_count_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str != c && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

static char	**ft_split_helper(size_t words, const char *s, char c, char **ret)
{
	size_t	k;
	size_t	word_len;

	k = 0;
	while (k < words)
	{
		while (*s == c && *s)
			s++;
		word_len = ft_count_len(s, c);
		ret[k] = malloc((word_len + 1) * sizeof(char));
		if (!ret[k])
			return (free_all(ret, k));
		ft_strlcpy(ret[k], s, word_len + 1);
		s += word_len;
		k++;
	}
	ret[k] = NULL;
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**ret;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ret = malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret = ft_split_helper(words, s, c, ret);
	return (ret);
}
