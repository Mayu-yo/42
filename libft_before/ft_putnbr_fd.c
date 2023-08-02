/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:12:54 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/01 18:33:33 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	is_minus(long num, int fd)
{
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	return (num);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	num;

	num = n;
	num = is_minus(n, fd);
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = '0' + (num % 10);
	write(fd, &c, 1);
}
