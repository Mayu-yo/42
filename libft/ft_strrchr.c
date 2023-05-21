#include "libft.h"

char *ft_strrchr(const char *s, int c){
	const unsigned char *p = (const unsigned char *)s;
	const unsigned char *ret = NULL;

	while(*p != '\0'){
		if(*p == c)
			ret = p;
		p++;
	}
	if(c == '\0')
		return (char *)p;
	return (char *)ret;
}

// #include <stdio.h>
// int main(){
// 	char c[] = "asdfgda";
// 	char *ret;
// 	ret = ft_strrchr(c, 100);
// 	printf("%s", ret);
// 	return 0;
// }