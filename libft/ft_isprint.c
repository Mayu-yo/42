/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:34:32 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:34:46 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isprint('a');
// 	printf("%d", ret);
// 	ret = ft_isprint('A');
// 	printf("%d", ret);
// 	ret = ft_isprint('z');
// 	printf("%d", ret);
// 	ret = ft_isprint('Z');
// 	printf("%d", ret);
// 	ret = ft_isprint('1');
// 	printf("%d", ret);
// 	ret = ft_isprint('9');
// 	printf("%d", ret);
// 	ret = ft_isprint('/');
// 	printf("%d", ret);
// 	return 0;
// }
