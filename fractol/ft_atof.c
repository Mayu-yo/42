/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:11:02 by mayu              #+#    #+#             */
/*   Updated: 2023/08/15 12:28:15 by mayyamad         ###   ########.fr       */
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

double	calc_decimal_point(char *num, double integer)
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
		return (ret);
	else
		error_message();
	exit (0);
}

double	calc_int_part(char *num, int negative)
{
	size_t	i;
	double	ret;

	i = 0;
	ret = 0;
	
	while ('0' <= num[i] && num[i] <= '9')
	{
		ret = ret * 10 + num[i] - '0';
		if ((ret > INT_MAX && negative == 1) || (ret - 1 > INT_MAX && negative == -1))
			error_message();
		i++;
	}
	if (num[i] == '.' && i > 0 && ('0' <= num[i - 1] && num[i - 1] <= '9'))
		ret = calc_decimal_point(&num[i + 1], ret);
	else if (num[i] == '\0')
		return (ret * negative);
	else
		error_message();
	return (ret * negative);
}

double	ft_atof(char *num)
{
	int		negative;
	double	ret;

	ret = 0;
	negative = 1;
	if (num[0] == '-')
	{
		negative = -1;
		ret = calc_int_part(&num[1], negative);
	}
	else
		ret = calc_int_part(num, negative);
	return (ret);
}

// #include <stdio.h>
// int main (){
// 	double num;
// 	num = ft_atof("1.1d25");
// 	printf("%f\n",num);
// 	// for (int i = 0; i < 10; i++){
// 	// 	num = pow((0.1), i);
// 	// 	printf("%f\n",num);
// 	// }
// 	return 0;
// }