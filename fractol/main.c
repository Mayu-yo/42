// #include "fractal.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void error_output(){
	write(1, "Usage: ./fractal [julia] or [mandelbrot]\n", 42);
	exit (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_output();
	if (ft_strncmp(argv[1],"julia",5) == 0)
	{
		printf("julia");
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		printf("mandelbrot");
	}
	else
		error_output();
	return (0);
}