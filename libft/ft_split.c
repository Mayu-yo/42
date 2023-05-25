/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 16:37:38 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*str != '\0')
// 	{
// 		str++;
// 		i++;
// 	}
// 	return (i);
// }

char	**ft_split(char const *s, char c)
{
	char **ret;
	int i = 0;
	int j = 0;
	int flag = 0;
	int len = ft_strlen(s);
	ret = (char **)malloc((len + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[0] = (char *)malloc((len + 1) * sizeof(char));
	if (ret[0] == NULL)
	{
		free(ret);
		return NULL;
	}
	if(s[0] == c || s[0] == '\0')
		flag = 1;
	while (*s != '\0')
	{
		if (*s == c && flag == 0)
		{//初めて区切り文字が出現した場合
			ret[i][j] = '\0';
			flag = 1;
			i++;
			j = 0;
			ret[i] = (char *)malloc(ft_strlen(s));
		}
		else if (*s != c)
		{
			if (flag == 1)//前の文字が区切り文字だった場合
				flag = 0;
			ret[i][j] = *s;
			j++;
		}
		s++;
	}
	if(flag == 1)
		ret[i] = NULL;
	else
	{
		ret[i][j] = '\0';
		ret[i + 1] = NULL;
	}
	return (ret);
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
