/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:33:31 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:33:33 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isdigit('a');
// 	printf("%d", ret);
// 	ret = ft_isdigit('A');
// 	printf("%d", ret);
// 	ret = ft_isdigit('z');
// 	printf("%d", ret);
// 	ret = ft_isdigit('Z');
// 	printf("%d", ret);
// 	ret = ft_isdigit('1');
// 	printf("%d", ret);
// 	ret = ft_isdigit('9');
// 	printf("%d", ret);
// 	ret = ft_isdigit('/');
// 	printf("%d", ret);
// 	return 0;
// }
