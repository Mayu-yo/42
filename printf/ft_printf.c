#include "ft_printf.h"
// #include <stdio.h>

static int format_check(va_list args, const char format)
{
	int len;
	int	num_count[1];

	len = 0;
	num_count[0] = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')//0x~~
		len += ft_puthex(va_arg(args, unsigned long long), 0);
	else if (format == 'd')
		len += ft_atoi_print(va_arg(args, char *), num_count);
	else if (format == 'i')
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
			if (var_len == -1)
				return (-1);
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
	len = ft_printf("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
	printf("\nlen: %d", len);

	return 0;
}