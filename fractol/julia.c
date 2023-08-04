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

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <real_part_of_c> <imaginary_part_of_c>\n", argv[0]);
        return 1;
    }

    t_complex c;
    c.real = ft_atof(argv[1]);
    c.imag = ft_atof(argv[2]);

    mlx_init();
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Julia Set");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iter = julia_set(x, y, 100, c);
            int color = iter * 255 / 100;
            int pixel_color = (color << 16) | (color << 8) | color;
            mlx_pixel_put(mlx, win, x, y, pixel_color);
        }
    }

    mlx_loop(mlx);

    return 0;
}
