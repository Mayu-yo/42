#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_count_len(int n, size_t base)
{
	int	count;

	count = 0;
	while (n / base)
	{
		n /= base;
		count++;
	}
	return (count + 1);
}
