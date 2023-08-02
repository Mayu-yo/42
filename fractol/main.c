#include "fractal.h"

void error_output(){
	write(1, "Usage: ./fractal [julia] or [mandelbrot]\n", 42);
	exit (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_output();
	if (argv[1] == "julia")
	{

	}
	else if (argv[1] == "mandelbrot")
	{

	}
	else
		error_output();
	return (0);
}