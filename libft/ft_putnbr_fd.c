/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:12:54 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/29 05:22:43 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	is_minus(long num, int fd)
{
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	return (num);
}

#include <stdio.h>
void	ft_putnbr_fd2(int n, int fd)
{
	char	c;
	long	num;

	num = n;
	num = is_minus(n ,fd);
	if (num >= 10)
		ft_putnbr_fd2(num / 10, fd);
	c = '0' + (num % 10);
	write(fd, &c, 1);
}