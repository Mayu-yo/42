#include "libft.h"

#include <stdio.h>
int main(){
	char *ret;
	ret = ft_memchr("asdfg",100,1);
	printf("%s",ret);
	return 0;
}

void *ft_memchr(const void *s, int c, size_t n){
	const unsigned char *p = s;

	while(*p != (unsigned char)c){
		if(*p == '\0' || n == 0)
			return NULL;
		p++;
		n--;
	}
	return (void *)p;
}