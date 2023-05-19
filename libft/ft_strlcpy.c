#include "libft.h"

int	copy(unsigned int mojisu, char *dest, const char *src, unsigned int dstsize)
{
	unsigned int	count;

	count = 0;
	if (dstsize <= mojisu)
	{
		while (count < dstsize - 1)
		{
			dest[count] = src[count];
			count++;
		}
		dest[dstsize - 1] = '\0';//
	}
	else if (mojisu < dstsize)
	{
		while (src[count] != '\0')
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (mojisu);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	mojisu;
	int				count;

	count = 0;
	mojisu = 0;
	if (dstsize == 0)
	{
		return (0);
	}
	while (src[mojisu] != '\0')
	{
		mojisu++;
	}
	copy(mojisu, dst, src, dstsize);
	return (mojisu);
}