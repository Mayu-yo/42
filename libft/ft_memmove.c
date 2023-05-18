#include "libft.h"

#include <stdio.h>
int main(){
	char a[] = "asdfg";
	char b[] = "qw\0rt";
	char *ret;
	ret = ft_memmove(a+3,a,4);
	printf("%s",ret);
	return 0;
}

void *ft_memmove(void *dest, const void *src, size_t n){
	unsigned char *d = dest;
	const unsigned char *s = src;
	if(dest == src){
		return(dest);
	}
	if(dest < src){
		while(n > 0){
		*d = *s;
		d++;
		s++;
		n--;
		}
	}else{
		while(n > 0){
		d[n-1] = s[n-1];
		n--;
		}
	}
	return(dest);
}