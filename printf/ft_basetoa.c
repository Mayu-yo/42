#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_reverse(char *str)
{
	size_t	str_len;
	size_t	i;
	char	buf;

	i = 0;
	str_len = ft_strlen(str);
	while (str_len / 2 > i)
	{
		buf = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = buf;
		i++;
	}
	str[str_len] = '\0';
	return (str);
}

char	*convert(long n, int flag, size_t len, int base)
{
	char	buf;
	char	*str;
	int		i;

	i = 0;
	if (flag == 0)
		str = (char *)malloc(len + 1);
	if (flag == 1)
		str = (char *)malloc(len + 2);
	if (str == NULL)
		return (NULL);
	while (n != 0)
	{
		buf = n % base;
		str[i] = buf + '0';
		n /= base;
		i++;
	}
	if (flag == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	count_len(int n)
{
	int	count;

	count = 0;
	while (n / 10)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

char	*basetoa(int n, unsigned int base)
{
	int		flag;
	char	*str;
	int		len;
	long	n_long;

	n_long = n;
	flag = 0;
	len = count_len(n_long);
	if (n_long == 0)
	{
		str = (char *)malloc(len + 1);
		*str = '0';
		return (str);
	}
	if (n_long < 0)
	{
		n_long = -n_long;
		flag = 1;
	}
	str = (char *)malloc(len + 1 + flag);
	if (str == NULL)
		return (NULL);
	str = convert(n_long, flag, len, base);
	return (ft_reverse(str));
}
