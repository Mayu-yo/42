#include <unistd.h>

char	*basetoa(int n, unsigned int base);

int	ft_putchar(char c)
{
	char	ch[1];

	ch[0] = c;
	write(1, ch, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		len;

	len = 0;
	if (s == NULL)
		return 0;
	while (s[len] != '\0')
		len++;
	write(1, s, len);
	return (len);
}

int	ft_putnbr(int n, int *count)
{
	char	c;
	long	num;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	c = '0' + (num % 10);
	*count++;
	write(1, &c, 1);
	return 0;
}

int	count_hex_len(int n)
{
	int	count;

	count = 0;
	while (n / 16)
	{
		n /= 16;
		count++;
	}
	return (count + 1);
}

#include <stdlib.h>
int ft_puthex(long long n)
{
	char *ret;
	int len;

	len = 0;
	ret = (char *)malloc(count_hex_len(n));
	ret = basetoa(n, 16);
	while (ret[len] != '\0')
	{
		write(1, &ret[len], 1);
	}
	return (len);
}