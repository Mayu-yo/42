#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;

	if(dst == NULL && src == NULL)
		return NULL;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

// #include <stdio.h>
// int main(){
// 	char *ret = ft_memcpy(((void *)0), ((void *)0), 3);
// 	printf("%s", ret);
// 	char *ret2 = memcpy(((void *)0), ((void *)0), 3);
// 	printf("%s", ret2);
// 	return 0;
// }
