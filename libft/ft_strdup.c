#include "libft.h"

int main()
{
	return 0;
}

char *strdup(const char *s)
{
	size_t len = 0;
	char *dst;
	len = ft_strlen(s);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return NULL;
	ft_strlcpy(dst, s, len + 1);
	return dst;
}