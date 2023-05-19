#include "libft.h"

// int main(){
// 	void *ret;
// 	char ch[] = "123456789";
// 	ret = ft_memset(ch, 100, 3);
// 	write(1,ret,sizeof(ch)-1);
// 	return 0;
// }

void *ft_memset(void *buf, int ch, size_t n){
	unsigned char	*p = buf;
	unsigned char uc = (unsigned char)ch;

    while(n > 0){
        *p = uc;
		p++;
		n--;
    }
    return (buf);
}