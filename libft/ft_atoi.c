#include "libft.h"

#include <stdio.h>
int main()
{
	char str[] = "          +--+-+--++1234j234";
	int num;
	num = ft_atoi(str);
	printf("%d", num);
	return 0;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	fugou;

	fugou = 1;
	i = 0;
	i = mojiretsu(str);
	num = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			fugou *= -1;
		i++;
	}
	while (str[i] >= '0' && '9' >= str[i])
	{
		num = num * 10;
		num += str[i] - '0';
		i++;
	}
	num = num * fugou;
	return (num);
}

int	mojiretsu(char *str)
{
	int	i;
	int	fugou;

	fugou = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}