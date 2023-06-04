#include "ft_printf.h"

static void ft_put_only(long num)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = '0' + (num % 10);
	write(1, &c, 1);
}

int	ft_putnbr(int n)
{
	long	num;
	size_t	count;

	count = 0;
	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count += 1;
	}
	ft_put_only(num);
	count += ft_count_len(num, 10);
	return (count);
}

int ft_put_unsigned(unsigned int n)
{
	size_t	count;

	count = 0;
	ft_put_only(n);
	count += ft_count_len(n, 10);
	return (count);
}