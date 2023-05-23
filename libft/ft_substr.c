#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{

	const char *p = s;
	char *ret;
	size_t len1 = len;

	if(len == 0)
		return NULL;
	if(start >= ft_strlen(s))
		return NULL;
	while(start != 0){//startまでずらす
		start--;
		p++;
	}
	ret = (char *)malloc(len + 1);
	if(ret == NULL)
		return NULL;
	while(len != 0 && *p != '\0'){//コピー
		*ret = *p;
		p++;
		ret++;
		len--;
	}
	*ret = '\0';
	return (ret-len1);
}

// #include<stdio.h>
// int main (){
// 	char *ret = ft_substr("qwertyuo", 3, 4);
// 	printf("%s", ret);
// 	return 0;
// }