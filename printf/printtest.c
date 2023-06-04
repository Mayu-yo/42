#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int len = 0;
	if (s == NULL)
		return 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return len;
}

int ft_print_char(int num)
{
	return ft_putchar((char)num);
}

int ft_print_unsigned(unsigned int num)
{
	if (num >= 10)
		ft_print_unsigned(num / 10);
	return ft_putchar('0' + (num % 10));
}

int ft_print_signed(int num)
{
	if (num < 0)
	{
		ft_putchar('-');
		return ft_print_unsigned((unsigned int)(-num));
	}
	return ft_print_unsigned((unsigned int)num);
}

int ft_puthex(unsigned int num, int uppercase)
{
	const char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	if (num >= 16)
		ft_puthex(num / 16, uppercase);
	return ft_putchar(hex_digits[num % 16]);
}

static int format_check(va_list args, const char format)
{
	int len = 0;
	switch (format)
	{
		case 'c':
			len += ft_print_char(va_arg(args, int));
			break;
		case 's':
			len += ft_putstr(va_arg(args, char *));
			break;
		case 'p':
			len += ft_puthex((unsigned int)(uintptr_t)va_arg(args, void *), 0);
			break;
		case 'd':
		case 'i':
			len += ft_print_signed(va_arg(args, int));
			break;
		case 'u':
			len += ft_print_unsigned(va_arg(args, unsigned int));
			break;
		case 'x':
			len += ft_puthex(va_arg(args, unsigned int), 0);
			break;
		case 'X':
			len += ft_puthex(va_arg(args, unsigned int), 1);
			break;
		case '%':
			len += ft_putchar('%');
			break;
		default:
			len += ft_putchar(format);
			break;
	}
	return len;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += format_check(args, *format++);
		}
		else
		{
			len += ft_putchar(*format++);
		}
	}

	va_end(args);
	return len;
}

#include <stdio.h>

int main()
{
	ft_printf("%c%c%c\n", 'H', 'e', 'y');
	ft_printf("%s\n", "Hello, world!");
	ft_printf("%p\n", main);
	ft_printf("%d\n", 42);
	ft_printf("%u\n", 12345);
	ft_printf("%x\n", 255);
	ft_printf("%X\n", 255);
	ft_printf("%%\n");
	ft_printf("%c%%%s%%%p%%%d%%%u%%%x%%%X\n", 'A', "Text", main, 42, 12345, 255, 255);
	return 0;
}
