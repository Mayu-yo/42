// #include "ft_printf.h"

// static int	ft_putnbr(int n, int *count)
// {
// 	char	c;
// 	long	num;

// 	num = n;
// 	count[0] += 1;
// 	if (num < 0)
// 	{
// 		write(1, "-", 1);
// 		num = -num;
// 	}
// 	if (num >= 10)
// 		ft_putnbr(num / 10, count);
// 	c = '0' + (num % 10);
// 	write(1, &c, 1);
// 	return 0;
// }

// static int	skip_space(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
// 		i++;
// 	return (i);
// }

// int	ft_atoi_print(const char *str, int *count)
// {
// 	int		i;
// 	long	num;
// 	int		minus;

// 	minus = 1;
// 	i = skip_space(str);
// 	num = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 		{
// 			minus *= -1;
// 			count[0] += 1;
// 		}
// 		i++;
// 	}
// 	while (str[i] == '0')
// 		i++;
// 	while ('0' <= str[i] && str[i] <= '9')
// 	{
// 		num = num * 10 + str[i] - '0';
// 		i++;
// 	}
// 	ft_putnbr(num * minus, count);
// 	return (count[0]);
// }
