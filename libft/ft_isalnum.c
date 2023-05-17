#include "libft.h"

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isalnum('a');
// 	printf("%d", ret);
// 	ret = ft_isalnum('A');
// 	printf("%d", ret);
// 	ret = ft_isalnum('z');
// 	printf("%d", ret);
// 	ret = ft_isalnum('Z');
// 	printf("%d", ret);
// 	ret = ft_isalnum('1');
// 	printf("%d", ret);
// 	ret = ft_isalnum('9');
// 	printf("%d", ret);
// 	ret = ft_isalnum('/');
// 	printf("%d", ret);
// 	return 0;
// }

int ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}