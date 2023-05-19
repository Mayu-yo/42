#include "libft.h"

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_memcmp("qwert", "qwertadf", 6);
// 	printf("%d",ret);
// 	return 0;
// }

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1 = s1;
	const unsigned char *p2 = s2;

	while (*p1 == *p2 && (n-1) != 0)
	{
		p1++;
		p2++;
		n--;
	}
	return (*p1 - *p2);
}