#include "libft.h"

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isdigit('a');
// 	printf("%d", ret);
// 	ret = ft_isdigit('A');
// 	printf("%d", ret);
// 	ret = ft_isdigit('z');
// 	printf("%d", ret);
// 	ret = ft_isdigit('Z');
// 	printf("%d", ret);
// 	ret = ft_isdigit('1');
// 	printf("%d", ret);
// 	ret = ft_isdigit('9');
// 	printf("%d", ret);
// 	ret = ft_isdigit('/');
// 	printf("%d", ret);
// 	return 0;
// }

int ft_isdigit(int c)
{
	if ('1' <= c && c <= '9')
		return (1);
	else
		return (0);
}