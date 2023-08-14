/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:21:18 by mayu              #+#    #+#             */
/*   Updated: 2023/08/14 23:01:10 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	error_output(void)
{
	ft_putendl_fd("Usage: ./fractal [julia] real_number imaginary_number or [mandelbrot]\n", 2);
	exit (0);
}

int	main(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		julia(argc, argv);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argc == 2)
	{
		mandelbrot();
	}
	else
		error_output();
	return (0);
}
