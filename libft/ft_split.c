/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/26 10:25:25 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// char	**ft_split(char const *s, char c)
// {
// 	char **ret;
// 	int i = 0;
// 	int j = 0;
// 	int flag = 0;
// 	if(s == NULL)
// 		return (NULL);
// 	int len = ft_strlen(s);
// 	ret = (char **)malloc((len + 1) * sizeof(char *));
// 	if (ret == NULL)
// 		return (NULL);
// 	ret[0] = (char *)malloc((len + 1) * sizeof(char));
// 	if (ret[0] == NULL)
// 	{
// 		free(ret);
// 		return NULL;
// 	}
// 	if(s[0] == c || s[0] == '\0')
// 		flag = 1;
// 	while (*s != '\0')
// 	{
// 		if (*s == c && flag == 0)
// 		{//初めて区切り文字が出現した場合
// 			ret[i][j] = '\0';
// 			flag = 1;
// 			i++;
// 			j = 0;
// 			ret[i] = (char *)malloc(ft_strlen(s));
// 		}
// 		else if (*s != c)
// 		{
// 			if (flag == 1)//前の文字が区切り文字だった場合
// 				flag = 0;
// 			ret[i][j] = *s;
// 			j++;
// 		}
// 		s++;
// 	}
// 	if(flag == 1)
// 		ret[i] = NULL;
// 	else
// 	{
// 		ret[i][j] = '\0';
// 		ret[i + 1] = NULL;
// 	}
// 	return (ret);
// }

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int count = 0;
	int is_word = 0;

	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}

	return count;
}

static void	free_memory(char **arr, int size)
{
	while (size >= 0)
	{
		free(arr[size]);
		size--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		result[i] = ft_substr(s, 0, j);
		if (result[i] == NULL)
		{
			free_memory(result, i - 1);
			return (NULL);
		}
		s += j;
		i++;
	}
	result[i] = NULL;
	return (result);
}


// #include <stdio.h>
// int main(){
// 	char **ret;
// 	ret = ft_split(",,,hello,,,world,,,42,,,tokyo,,,,", ',');
// 	printf("%s\n", ret[0]);
// 	printf("%s\n", ret[1]);
// 	printf("%s\n", ret[2]);
// 	printf("%s\n", ret[3]);
// 	printf("%s\n", ret[4]);
// 	return 0;
// }
