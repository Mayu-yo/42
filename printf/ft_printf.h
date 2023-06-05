/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:28:01 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/05 13:17:27 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <stdarg.h>

int ft_printf(const char *arg_1, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int ft_putaddress(unsigned long n, int uporlow);
size_t	ft_strlen(const char *str);
size_t	ft_count_len(long long n, size_t base);
int ft_puthex(unsigned long n, int uporlow);
char	*ft_itoa(int n);
int ft_print_char(int num);
int ft_put_unsigned(unsigned int n);


#endif
