#include "libft.h"
#include <unistd.h>

void *ft_memset(void *buf, int ch, size_t n);

int main(){
	void *ret;
	char ch[] = "123456789";
	ret = ft_memset(ch, 3, 3);
	write(1,ret,sizeof(ch)-1);
	return 0;
}

void *ft_memset(void *buf, int ch, size_t n){
	unsigned char	*p = buf;

    while(n != 0){
        *p = (unsigned char)ch;
		p++;
		n--;
    }
    return (buf);
}