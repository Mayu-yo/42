#include "libft.h"

int main(){
	return 0;
}

void *ft_memchr(const void *s, int c, size_t n){
	const unsigned char *p = s;

	while(*p != c){
		if(*p == '\0')
			return 0;
		p++;
	}
	return p;
}