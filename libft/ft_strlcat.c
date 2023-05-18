#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	j = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (s_len + size);
	while (src [i] != '\0' && i < size - d_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char dest[20] = "AE";
    char src[] = "";
    int x = 6;
   
    unsigned int result1 = strlcat(dest, src, x);
    printf("%s: %u\n", dest, result1);
    return(0);
}
*/