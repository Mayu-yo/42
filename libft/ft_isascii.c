#include "libft.h"

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isascii('a');
// 	printf("%d", ret);
// 	ret = ft_isascii('A');
// 	printf("%d", ret);
// 	ret = ft_isascii('\t');
// 	printf("%d", ret);
// 	ret = ft_isascii('	');
// 	printf("%d", ret);
// 	ret = ft_isascii('1');
// 	printf("%d", ret);
// 	ret = ft_isascii('9');
// 	printf("%d", ret);
// 	ret = ft_isascii('/');
// 	printf("%d", ret);
// 	return 0;
// }

int ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}