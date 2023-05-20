#include "libft.h"

// unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	unsigned int	d_len;
// 	unsigned int	s_len;

// 	i = 0;
// 	j = 0;
// 	d_len = ft_strlen(dest);
// 	s_len = ft_strlen(src);
// 	if (size <= d_len)
// 		return (s_len + size);
// 	while (src [i] != '\0' && i < size - d_len - 1)
// 	{
// 		dest[j] = src[i];
// 		i++;
// 		j++;
// 	}
// 	dest[d_len + j] = '\0';
// 	return (d_len + s_len);
// }
unsigned int ft_strlcat(char *dst, char *src, unsigned int size) {
    unsigned int dst_len = strlen(dst);
    unsigned int src_len = strlen(src);
    unsigned int total_len = dst_len + src_len;
    
    if (size <= dst_len)
        return src_len + size;
    
    unsigned int copy_len = size - dst_len - 1;
    strncat(dst + dst_len, src, copy_len);
    dst[size - 1] = '\0';
    
    return total_len;
}


/*
#include <stdio.h>
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