#include "libft.h"

// int main(){
// 	void *ret;
// 	char ch[] = "123456789";
// 	ret = ft_bzero(ch, 0, 3);
// 	write(1,ret,sizeof(ch)-1);
// 	return 0;
// }

void *ft_bzero(void *buf, size_t n){
	unsigned char	*p = buf;
	unsigned char uc = 0;

    while(n != 0){
        *p = uc;
		p++;
		n--;
    }
    return (buf);
}