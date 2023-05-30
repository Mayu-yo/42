/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/30 13:11:09 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word_len(const char *s, char c, int which_len)
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

char	**split_string(char const *s, char c, char **ret, int flag)
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
			ret[i] = (char *)malloc(count_word_len(s, c));
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
	ret = split_string(s, c, ret, flag);
	return (ret);
}

#include <stdio.h>
int main()
{
    const char *s = "\0aa\0bbb";
    char c = 'a';
    char **result = ft_split(s, c); // split関数を呼び出して文字列を分割

    if (result == NULL)
    {
        printf("Split failed. Memory allocation error.\n");
        return 1;
    }

    // 分割された文字列の表示
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
    }

    // 分割後の文字列領域の解放
    for (int i = 0; result[i] != NULL; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}