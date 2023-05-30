/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:28:01 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/30 16:08:24 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <limits.h>
# include <stdarg.h>

int ft_printf(const char *, ...);
int format_check(va_list argd, const char format);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int *count);
int	count_hex_len(int n);
int ft_puthex(long long n);

#endif
