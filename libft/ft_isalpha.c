/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:30:34 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:30:36 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isalpha('a');
// 	printf("%d", ret);
// 	ret = ft_isalpha('A');
// 	printf("%d", ret);
// 	ret = ft_isalpha('z');
// 	printf("%d", ret);
// 	ret = ft_isalpha('Z');
// 	printf("%d", ret);
// 	ret = ft_isalpha('1');
// 	printf("%d", ret);
// 	ret = ft_isalpha('9');
// 	printf("%d", ret);
// 	ret = ft_isalpha('/');
// 	printf("%d", ret);
// 	return 0;
// }
