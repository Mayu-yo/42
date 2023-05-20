/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:28:21 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/20 13:28:26 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main()
// {
// 	int ret = 0;
// 	ret = ft_isalnum('a');
// 	printf("%d", ret);
// 	ret = ft_isalnum('A');
// 	printf("%d", ret);
// 	ret = ft_isalnum('z');
// 	printf("%d", ret);
// 	ret = ft_isalnum('Z');
// 	printf("%d", ret);
// 	ret = ft_isalnum('1');
// 	printf("%d", ret);
// 	ret = ft_isalnum('9');
// 	printf("%d", ret);
// 	ret = ft_isalnum('/');
// 	printf("%d", ret);
// 	return 0;
// }
