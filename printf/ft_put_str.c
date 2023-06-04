#include "ft_printf.h"


int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[len] != '\0')
		len++;
	write(1, s, len);
	return (len);
}

int ft_print_char(int num)
{
	int len;
    char c;

	len = 0;
	c = (char)num;
    len += ft_putchar(c);
	return (len);
}
