#include "printf.h"

int	ft_putchar_fd(char c)
{
	char	ch[1];

	ch[0] = c;
	write(1, ch, 1);
	return 1;
}

int format_check(va_list args, const char format)
{
	int len;
	int	*num_count;

	len = 0;
	num_count = NULL;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')//void pointer hexadecimal format
		len += ft_puthex(va_arg(args, unsigned long long));//ここの型の意味がわからん
	else if (format == 'd')
	{
		len += ft_putnbr((va_arg(args, int)), num_count);
		len += *num_count;
	}
	else if (format == 'i')
	{
		ft_putnbr((va_arg(args, int)), num_count);
		len += *num_count;
	}
	else if (format == 'u')//unsigned decimal
		len += ft_puthex(va_arg(args, unsigned int));
	else if (format == 'x')//hexadecimal
		len += ft_puthex(va_arg(args, unsigned long));
	else if (format == '%')
		len += ft_putchar(ft_putchar('%'));
	return (len) ;
}

int ft_printf(const char *arg_1, ...)
{
	int i;
	va_list	ap;
	va_start(ap, arg_1);

	i = 0;
	while (arg_1[i] != '\0')
	{
		if (arg_1[i] == '%')
		{
			i++;
			format_check(ap, arg_1[i]);
		}
		else
			ft_putchar_fd(arg_1[i]);
		i++;
	}
	va_end(ap);
	return 0;//出力した文字数
}
int main()
{
	ft_printf("%s","4512345");
	return 0;
}