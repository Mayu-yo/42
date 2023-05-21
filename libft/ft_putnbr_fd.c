/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:12:54 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/21 14:12:57 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	*ret;

	ret = (char *)malloc(12);
	if (ret == NULL)
		return (NULL);
	ret = ft_itoa(n);
	len = ft_strlen(ret);
	write(fd, ret, len);
}

// int main (){
// 	ft_putnbr_fd(45678,1);
// 	return 0;
// }
