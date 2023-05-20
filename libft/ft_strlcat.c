#include "libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

unsigned int ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int src_len = strlen(src);
	if (dst == NULL)
		return src_len;
	unsigned int dst_len = strlen(dst);
	unsigned int total_len = dst_len + src_len;
	
	if (size <= dst_len)
		return (src_len + size);
	
	unsigned int copy_len = size - dst_len - 1;
	ft_strncat(dst + dst_len, src, copy_len);
	dst[size - 1] = '\0';
	
	return total_len;
}

// #include <stdio.h>
// int main()
// {
//     char dest[20] = "";
//     char src[] = "qwy";
//     int x = 0;
   
//     unsigned int result = ft_strlcat(NULL, src, x);
//     printf("自作%s: %u\n", dest, result);
// 	unsigned int result1 = strlcat(NULL, src, x);
//     printf("本物%s: %u\n", dest, result1);
//     return(0);
// }
