#include "printf.h"

static char	*ft_reverse(char *str)
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

static char	*convert(long n, int flag, size_t len, int uporlow)
{
	char	buf;
	char	*str;
	int		i;
	char	ch;

	i = 0;
	if(uporlow == 0)
		ch = 'a';
	else
		ch = 'A';
	if (flag == 0)
		str = (char *)malloc(len + 1);
	if (flag == 1)
		str = (char *)malloc(len + 2);
	if (str == NULL)
		return (NULL);
	while (n != 0)
	{
		buf = n % 16;
		if(buf < 10)
			str[i] = buf + '0';
		else
			str[i] = buf + ch - 10;
		n /= 16;
		i++;
	}
	// if (flag == 1)
	// {
	// 	str[i] = '-';
	// 	i++;
	// }
	str[i] = '\0';
	return (str);
}

static char	*convert_hex(long long n, int uporlow)
{
	int		flag;
	char	*str;
	int		len;

	flag = 0;
	len = ft_count_len(n, 16);
	if (n == 0)
	{
		str = (char *)malloc(len + 1);
		*str = '0';
		return (str);
	}
	str = (char *)malloc(len + 1 + flag);
	if (str == NULL)
		return (NULL);
	str = convert(n, flag, len, uporlow);
	return (ft_reverse(str));
}

int ft_puthex(long long n, int uporlow)
{
	char *ret;
	int hex_len;

	if (n < 0)
		return (-1);
	hex_len = ft_count_len(n, 16);
	ret = (char *)malloc(hex_len);
	ret = convert_hex(n, uporlow);
	write(1, ret, hex_len);
	return (hex_len);
}

// int main(){
// 	ft_puthex(-1234567, 1);
// 	return 0;
// }