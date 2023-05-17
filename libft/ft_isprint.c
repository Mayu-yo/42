#include "libft.h"

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isprint('a');
// 	printf("%d", ret);
// 	ret = ft_isprint('A');
// 	printf("%d", ret);
// 	ret = ft_isprint('z');
// 	printf("%d", ret);
// 	ret = ft_isprint('Z');
// 	printf("%d", ret);
// 	ret = ft_isprint('1');
// 	printf("%d", ret);
// 	ret = ft_isprint('9');
// 	printf("%d", ret);
// 	ret = ft_isprint('/');
// 	printf("%d", ret);
// 	return 0;
// }

int ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}