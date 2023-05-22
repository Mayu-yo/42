/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:11:39 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/22 11:07:38 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\n';
	write(fd, str, len + 1);
}

// int main (){
// 	ft_putendl_fd("asdfg",1);
// 	return 0;
// }
