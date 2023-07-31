/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:05:52 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/05 15:09:19 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_check(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putaddress(va_arg(args, unsigned long), 0);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += format_check(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
