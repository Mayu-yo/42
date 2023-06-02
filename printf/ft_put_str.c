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
	if (s == NULL)
		return 0;
	while (s[len] != '\0')
		len++;
	write(1, s, len);
	return (len);
}

// int main (){
// 	ft_putchar(1);
// 	return 0;
// }