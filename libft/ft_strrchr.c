#include "libft.h"

char *ft_strrchr(const char *s, int c){
	const unsigned char *p = (const unsigned char *)s;
	const unsigned char *ret = NULL;

	while(*p != '\0'){
		if(*p == (unsigned char)c)
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
// 	ret = ft_strrchr(c, 'd' - 256);
// 	printf("%s\n", ret);
// 	ret = strrchr(c, 'd' - 256);
// 	printf("%s", ret);
// 	return 0;
// }