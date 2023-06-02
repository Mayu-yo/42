#include "ft_printf.h"
// #include <stdio.h>
static int	ft_putnbr(long long num, int *count)
{
	char	c;

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

static const char	*skip_space(const char *str)
{
	int	i;

	i = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	return (str);
}

int	ft_atoi_print(const char *str, int *count)
{
	int		i;
	long long	num;
	int		minus;

	minus = 1;
	if (!str)
		return (count[0]);
	//str = malloc(ft_strlen(str));//sippaisyori poinntadeatsukau?
	str = skip_space(str);
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			minus *= -1;
			count[0] += 1;
		}
		str++;
	}
	while (*str == '0')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	ft_putnbr(num * minus, count);
	return (count[0]);
}

/*-------------------------------------------------------*/
static int format_check(va_list args, const char format)
{
	int len;
	int	num_count[1];

	len = 0;
	num_count[0] = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putaddress(va_arg(args, unsigned long long), 0);
	else if (format == 'd' || format == 'i')
		len += ft_atoi_print(va_arg(args, char *), num_count);
	else if (format == 'u')//unsigned decimal
		len += ft_puthex(va_arg(args, unsigned long), 0);
	else if (format == 'x')//hexadecimal
		len += ft_puthex(va_arg(args, unsigned long), 1);
	else if (format == '%')
		len += ft_putchar(ft_putchar('%'));
	return (len) ;
}

int ft_printf(const char *arg_1, ...)
{
	size_t i;
	size_t len;
	int var_len;
	va_list	ap;
	va_start(ap, arg_1);

	i = 0;
	len = 0;
	while (arg_1[i] != '\0')
	{
		if (arg_1[i] == '%')
		{
			i++;
			var_len = format_check(ap, arg_1[i]);
			// if (var_len == -1)
			// 	return (-1);
			len += var_len;
		}
		else
			len += ft_putchar(arg_1[i]);
		i++;
	}
	va_end(ap);
	return (len);//出力した文字数
}

#include <stdio.h>
int main()
{
	int len;
	char *a;

	a = malloc(5);
	a = "hello";
	// len = ft_printf("%d", 12345);
	// printf("\nlen: %d", len);
	// puts("\n");
	// len = printf("%d",12345);
	// printf("\nlen: %d", len);
	int *count;
	count = NULL;
	ft_atoi_print(a, count);

	return 0;
}