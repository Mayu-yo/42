#include "ft_printf.h"

/*-----------------------------------------------------*/

static int format_check(va_list args, const char format)
{
	int len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putaddress(va_arg(args, void *), 0);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')//unsigned decimal
		len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')//hexadecimal
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')//hexadecimal
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == '%')
	{
		len += ft_putchar('%');
		va_arg(args, int);
	}
	return (len) ;
}

int ft_printf(const char *format, ...)
{
	// size_t i;
	size_t len;
	va_list	args;
	va_start(args, format);

	// i = 0;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += format_check(args, *format++);
			va_arg(args, int);//aをインクリメントする方法がわからんくて使わんのに呼び出してる
		}
		else
			len += ft_putchar(*format++);
		// i++;
	}
	va_end(args);
	return (len);//出力した文字数
}

#include <stdio.h>
int main()
{
	int len;
// // 	// char *a;

// // 	// a = malloc(5);
// // 	// a = "hello";
// // 	len = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// // 	printf("\nlen: %d", len);
// // 	puts("\n");
// // 	len = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// // 	printf("\nlen: %d", len);

	len = ft_printf("%p", (void *)-1);
	printf("\nlen: %d", len);
	// puts("\n");
	// len = printf("%%%c%%%s", 'A',42);
	// printf("\nlen: %d", len);

	return 0;
}
