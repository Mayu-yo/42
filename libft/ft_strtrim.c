#include "libft.h"

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
//     size_t	srclen = 0;
//     size_t	i;

//     while (src[srclen] != '\0')
//         srclen++;
//     if (dstsize == 0)
//         return (srclen);
//     i = 0;
//     while (i < dstsize - 1 && src[i] != '\0')
//     {
//         dst[i] = src[i];
//         i++;
//     }
//     dst[i] = '\0';
//     return (srclen);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*str != '\0')
// 	{
// 		str++;
// 		i++;
// 	}
// 	return (i);
// }

int	is_trim_char(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return 1;
		set++;
	}
	return 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t len;
	char *ret;

	if (s1 == NULL)
		return NULL;

	start = 0;
	len = ft_strlen(s1);

	while (is_trim_char(s1[start], set))
		start++;

	while (len > start && is_trim_char(s1[len - 1], set))
		len--;

	ret = (char *)malloc(len - start + 1);
	if (ret == NULL)
		return NULL;

	ft_strlcpy(ret, s1 + start, len - start + 1);

	return ret;
}

// #include <stdio.h>
// int main(){
// 	char *ret;
// 	char *str = "    hello world     ";

// 	ret = (char *)malloc(strlen(str));
// 	ret = ft_strtrim(str, " ");
// 	printf("%s",ret);
// 	return 0;
// }

