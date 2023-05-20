/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:49:32 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:50:49 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*p;
	unsigned char	uc;

	p = buf;
	uc = (unsigned char)ch;
	while (n > 0)
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
// 	ret = ft_memset(ch, 100, 3);
// 	write(1,ret,sizeof(ch)-1);
// 	return 0;
// }
