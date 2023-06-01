/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/01 03:59:31 by mayu             ###   ########.fr       */
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
			while (s[i] != c && i < ft_strlen(s))
			{
				i++;
				count++;
			}
			break;
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
			ret[i] = (char *)malloc(count_word_len(s, c, i, 0) + 1);
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

char	**ft_split(char const *s, char c)
{
	size_t i;
	char	**ret;
	int		flag;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = malloc((count_word_len(s, c, 0, 1) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	ret[0] = malloc((count_word_len(s, c, i, 0) + 1) * sizeof(char));
	if (ret[0] == NULL)
	{
		free(ret);
		return (NULL);
	}
	flag = 0;
	if (s[0] == c || s[0] == '\0')
		flag = 1;
	ret = ft_split2(s, c, ret, i);
	return (ret);
}

int main(){
	ft_split("  tripouille  42  ", ' ');
	return 0;
}