#include "libft.h"

int main(){
	char a[] = "asdfg";
	char b[] = "qwert";
	write(1,a,sizeof(a));
	write(1,b,sizeof(b));
	write(1,"\n",1);
	ft_memcpy(a,b,3);
	write(1,a,sizeof(a));
	write(1,b,sizeof(b));
	return 0;
}

void *ft_memcpy(void *dst, const void *src, size_t n){
	unsigned char *d = dst;
	const unsigned char *s = src;
	while(n > 0){
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}