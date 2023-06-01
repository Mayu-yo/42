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
	count[0] += 1;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10, count);
	c = '0' + (num % 10);
	write(1, &c, 1);
	return 0;
}

int	skip_space(const char *str)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi_print(const char *str, int *count)
{
	int		i;
	long	num;
	int		minus;

	minus = 1;
	i = skip_space(str);
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			minus *= -1;
			count[0] += 1;
		}
		i++;
	}
	while (str[i] == '0')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	ft_putnbr(num * minus, count);
	return (count[0]);
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
	int hex_len;

	len = 0;
	hex_len = count_hex_len(n);
	ret = (char *)malloc(hex_len);
	ret = basetoa(n, 16);
	while (ret[len] != '\0' && len < hex_len)
	{
		write(1, &ret[len], 1);
	}
	return (len);
}