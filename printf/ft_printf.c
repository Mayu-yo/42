#include "printf.h"
#include <stdio.h>

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return 1;
}

int format_check(va_list args, const char format)
{
	int len;
	int	num_count[1];

	len = 0;
	num_count[0] = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')//void pointer hexadecimal format
		len += ft_puthex(va_arg(args, unsigned long long));//ここの型の意味がわからん
	else if (format == 'd')
		len += ft_atoi_print(va_arg(args, char *), num_count);
	else if (format == 'i')
		len += ft_atoi_print(va_arg(args, char *), num_count);
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
	size_t i;
	size_t len;
	va_list	ap;
	va_start(ap, arg_1);

	i = 0;
	while (arg_1[i] != '\0')
	{
		if (arg_1[i] == '%')
		{
			i++;
			len = format_check(ap, arg_1[i]);
		}
		else
			len += ft_putchar_fd(arg_1[i]);
		i++;
	}
	va_end(ap);
	return (len);//出力した文字数
}

int main()
{
	int len;
	len = ft_printf("ret: %u","-4512344");
	printf("\nlen: %d", len);
	
	return 0;
}