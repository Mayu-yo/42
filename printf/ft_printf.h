/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:28:01 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/02 02:37:31 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <limits.h>
# include <stdarg.h>

int ft_printf(const char *arg_1, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_atoi_print(const char *str, int *count);
int ft_puthex(long long n, int uporlow);
size_t	ft_strlen(const char *str);
int	ft_count_len(int n, size_t base);

#endif
