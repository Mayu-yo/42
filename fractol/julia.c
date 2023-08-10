#include "fractal.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

int julia_set(int x, int y, int max_iter, t_complex c) {
    t_complex z;
    z.real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
    z.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

    int iter = 0;
    while (iter < max_iter && (z.real * z.real + z.imag * z.imag) < 4.0) {
        double temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        z.real = temp;
        iter++;
    }

    return iter;
}

void	draw_julia(t_complex c, t_data julia)
{
	for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iter = julia_set(x, y, 100, c);
            int color = iter * 255 / 100;
            int pixel_color = (color << 16) | (color << 8) | color;
            mlx_pixel_put(julia.mlx_ptr, julia.win_ptr, x, y, pixel_color);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <real_part_of_c> <imaginary_part_of_c>\n", argv[0]);
        return 1;
    }

    t_complex c;
    c.real = atof(argv[1]);
    c.imag = atof(argv[2]);

	t_data julia;
    mlx_init();
    julia.mlx_ptr = mlx_init();
    julia.win_ptr = mlx_new_window(julia.mlx_ptr, WIDTH, HEIGHT, "Julia Set");
	draw_julia(c, julia);
    mlx_loop(julia.mlx_ptr);

    return 0;
}
