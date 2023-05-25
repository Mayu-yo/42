/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:13:33 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 08:57:21 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
}


// int main (){
// 	ft_putstr_fd("asdfg",1);
// 	return 0;
// }
