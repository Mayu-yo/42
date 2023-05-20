#include "libft.h"

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
	ret[i][j] = '\0';
	ret[i + 1] = NULL;
	return (ret);
}

// #include <stdio.h>
// int main(){
// 	char **ret;
// 	ret = ft_split("a1sg112sd21", 49);
// 	printf("%s\n", ret[0]);
// 	printf("%s\n", ret[1]);
// 	printf("%s\n", ret[2]);
// 	return 0;
// }
