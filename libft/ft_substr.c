#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int i;
	const char *p = s;
	char *ret;

	i = 0;
	if(len == 0 || start >= ft_strlen(s))
	{
		ret = (char *)malloc(1);
		return (ret);
	}
	while(start != 0){//startまでずらす
		start--;
		p++;
	}
	ret = (char *)malloc(len + 1);
	if(ret == NULL)
		return NULL;
	while(len != 0 && *p != '\0'){//コピー
		ret[i] = *p;
		p++;
		i++;
		len--;
	}
	ret[i] = '\0';
	return (ret);
}

// #include<stdio.h>
// int main (){
// 	char *s = "libft-test-tokyo";
// 	char *ret = ft_substr(s, 0, 100);
// 	printf("%s", ret);
// 	return 0;
// }