/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:17:33 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:23:24 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *buf, size_t n)
{
	unsigned char	*p;
	unsigned char	uc;

	p = buf;
	uc = 0;
	while (n != 0)
	{
		*p = uc;
		p++;
		n--;
	}
	return (buf);
}

// int main(){
// 	void *ret;
// 	char ch[] = "123456789";
// 	ret = ft_bzero(ch, 0, 3);
// 	write(1,ret,sizeof(ch)-1);
// 	return 0;
// }
