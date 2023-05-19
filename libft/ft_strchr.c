#include "libft.h"

// int main(){
// 	char c[] = "asdfg";
// 	char *ret;
// 	ret = ft_strchr(c, 100);
// 	write(1, ret, sizeof(c));
// 	return 0;
// }

char *ft_strchr(const char *s, int c){
	const unsigned char *p = (const unsigned char *)s;

	while(*p != (unsigned char)c){
		if(*p == '\0' && c != '\0')
			return NULL;
		p++;
	}
	return (char *)p;
}