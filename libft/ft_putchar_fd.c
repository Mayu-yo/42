/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:10:11 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/21 14:10:52 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	ch[1];

	ch[0] = c;
	write(fd, ch, 1);
}

// int main(){
// 	ft_putchar_fd('z', 1);
// 	return 0;
// }
