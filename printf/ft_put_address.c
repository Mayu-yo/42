#include "ft_printf.h"

int ft_putaddress(unsigned long n, int uporlow)
{
	if (uporlow == 0)
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	return (ft_puthex(n, 0) + 2);
}