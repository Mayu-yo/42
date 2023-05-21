/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:13:33 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/21 16:38:42 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return;
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	write(fd, str, len);
}

// int main (){
// 	ft_putstr_fd("asdfg",1);
// 	return 0;
// }
