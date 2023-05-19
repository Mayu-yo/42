#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len){//文字列sのstart文字目からlen文字分をmallocで確保したchar*に入れて返す

	char *p = s;
	char ret = (char *)malloc(len);
	if(len == 0)
		return NULL;
	if(start >= ft_strlen(s))
		return NULL;
	while(start != 0 && p != '\0'){
		*ret = *p;
		ret++;
		start--;
		p++;
	}
	while(len != 0)

}