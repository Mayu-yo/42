#include "libft.h"

int main()
{
	return 0;
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int ret = 0;
	int i = 0;
	const unsigned char *p1 = s1;
	const unsigned char *p2 = s2;

	while (*p1 != *p2 && n != 0)
	{
		p1++;
		p2++;
		n--;
	}
	ret = *p1 - *p2;
		return (ret);
}