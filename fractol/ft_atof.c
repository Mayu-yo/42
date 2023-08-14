/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:11:02 by mayu              #+#    #+#             */
/*   Updated: 2023/08/15 02:52:14 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractal.h"
#include "libft/libft.h"
#include <stdio.h>

static void	error_message(void)
{
	ft_putendl_fd("invalid input", 2);
	exit (0);
}

double	calc_decimal_point(char *num, int integer, int minus_flag)
{
	int		i;
	double	digit;
	double	ret;

	i = 0;
	digit = 0.1;
	ret = integer;
	while ('0' <= num[i] && num[i] <= '9')
	{
		ret = ret + ((num[i] - '0') * digit);
		digit = digit * 0.1;
		i++;
	}
	if (num[i] == '\0')
		return (ret * minus_flag);
	else
		error_message();
	exit (0);
}

double	calc_int_part(char *num)
{
	size_t	i;
	double	ret;
	int		minus_flag;

	i = 0;
	ret = 0;
	minus_flag = 1;
	if (num[i] == '-')
	{
		minus_flag = -1;
		i++;
	}
	while ('0' <= num[i] && num[i] <= '9')
	{
		ret = ret * 10 + num[i] - '0';
		i++;
	}
	if (num[i] == '.' && i > 0 && ('0' <= num[i - 1] && num[i - 1] <= '9'))
		ret = calc_decimal_point(&num[i + 1], ret, minus_flag);
	else if (num[i] == '\0')
		return (ret * minus_flag);
	else
		error_message();
	return (ret);
}

double	ft_atof(char *num)
{
	double	ret;

	ret = 0;
	ret = calc_int_part(num);
	return (ret);
}

// #include <stdio.h>
// int main (){
// 	double num;
// 	num = ft_atof("0.125");
// 	printf("%f\n",num);
// 	// for (int i = 0; i < 10; i++){
// 	// 	num = pow((0.1), i);
// 	// 	printf("%f\n",num);
// 	// }
// 	return 0;
// }