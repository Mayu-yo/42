/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/01 18:06:01 by mayyamad         ###   ########.fr       */
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

int	count_word_len(const char *s, char c, size_t i, int which_len)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (which_len == 0)
		{
			while (s[i++] != c && i < ft_strlen(s) && which_len == 0)
				count++;
			break ;
		}
		if (which_len == 1)
		{
			if (s[i] != c && flag == 0)
			{
				count++;
				flag = 1;
			}
			if (s[i] == c)
				flag = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split2(char const *s, char c, size_t k, char **ret)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[k] != '\0')
	{
		if (s[k] == c)
		{
			while (s[k] == c)
				k++;
			ret[i++][j] = '\0';
			j = 0;
			if (k == ft_strlen(s))
				return (null_terminate_array(ret, i, j, 1));
			else
				ret[i] = (char *)malloc(count_word_len(s, c, k, 0) + 1);
			if (ret[i] == NULL)
				return (free_all(ret, i - 1));
		}
		if (s[k] != c && k < ft_strlen(s))
			ret[i][j++] = s[k];
		k++;
	}
	return (null_terminate_array(ret, i, j, 0));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**ret;

	i = 0;
	if (!s)
		return (NULL);
	ret = malloc((count_word_len(s, c, i, 1) + 1) * sizeof(char *));
	if (s[0] == '\0')
		return (null_terminate_array(ret, 0, 0, 1));
	if (ret == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	if (i == ft_strlen(s))
		return (null_terminate_array(ret, 0, 0, 1));
	ret[0] = malloc((count_word_len(s, c, i, 0) + 1) * sizeof(char));
	if (ret[0] == NULL)
		return (free_all(ret, 0));
	ret = ft_split2(s, c, i, ret);
	return (ret);
}

// int main() {
//     char *invalidPointer = NULL;
//     ft_split("     ", ' ');
//     return 0;
// }