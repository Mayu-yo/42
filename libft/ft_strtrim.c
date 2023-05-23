#include "libft.h"

int	space(const char *str)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	space_rev(const char *str, int i)
{
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i--;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int start;
	int len;
	int end;
	int i;
	int j;
	char *ret;

	j = 0;
	i = 0;
	while (s1[start] != '\0')
	{
		start = 0;
		len = ft_strlen(s1);
		end = space_rev(s1, len - 1);
		start = space(s1);
		ret = (char *)malloc(end - start + 2);
		if (ret == NULL)
	 		return NULL;
		while (s1[start] != '\0')
		{
			if (s1[start] == set[0])//setの１文字目と同じ文字を探す
			{
				i = 0;
				while(s1[start + i] == set[i])//単語が一致してるか確かめる
				{
					if(set[i] == '\0')
						start += i;
					i++;
				}
			}
			if(s1[start] == '\0')
				break;
			ret[j] = s1[start];
			j++;
			start++;
		}
	}
	return ret;
}

#include <stdio.h>
int main(){
	char *ret;
	char *str = "hello world";

	ret = (char *)malloc(strlen(str));
	ret = ft_strtrim(str, "world");
	printf("%s",ret);
	return 0;
}

	// while (*s1 != '\0'){
	// 	i = 0;
	// 	while(set[i] != '\0')
	// 	{
	// 		if(*s1 == set[i])
	// 		{
	// 			flag = 0;
	// 			break;
	// 		}
	// 		else if(set[i + 1] == '\0')
	// 		{
	// 			ret[j] = *s1;
	// 			j++;
	// 			flag = 1;
	// 		}
	// 		i++;
	// 	}
	// 	s1++;
	// }
	// if(flag == 1)
	// 	ret[j] = '\0';
	// else
	// 	ret[j + 1] = '\0';