#include "libft.h"

int main(){
	char c[] = "asdfg";
	char *ret;
	ret = ft_strchr(c, 100);
	write(1, ret, sizeof(c));
	return 0;
}

char *ft_strrchr(const char *s, int c){
	const unsigned char *p = (const unsigned char *)s;

	while(*p != '\0'){
		
		p++;
	}
	return (char *)p;
}