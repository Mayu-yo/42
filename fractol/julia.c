
#include "fractal.h"
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 130

int julia_set(int x, int y, t_complex c, double zoom) {
	double temp;
    int iter = 0;
    t_complex z;

    z.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / zoom;
    z.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / zoom;
    while (iter < MAX_ITER && (z.real * z.real + z.imag * z.imag) < 4.0) {
        temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        z.real = temp;
        iter++;
    }

    return iter;
}

// int julia_set_color(int iter)
// {
//     int color;
//     int pixel_color;

// 	color = iter * 255 / MAX_ITER;
// 	pixel_color = (color << 16) | (color << 8) | color;
// 	return (pixel_color);
// }
int julia_set_color(int iter)
{
    int red, green, blue;

    // Calculate color components based on iteration and main color
    red = (int)(64 + 0.3 * iter * (255 - 64) / MAX_ITER);
    green = (int)(64 + 0.5 * iter * (255 - 64) / MAX_ITER);
    blue = (int)(225 - 0.3 * iter * (225 - 64) / MAX_ITER);

    int pixel_color = (red << 16) | (green << 8) | blue;
    return pixel_color;
}

void draw_julia(t_data *img, t_complex c, double zoom)
{
	int x = 0;
	int y = 0;
	int iter = 0;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = julia_set(x, y, c, zoom);
			mlx_pixel_put(img->mlx_ptr, img->win_ptr, x, y, julia_set_color(iter));
			x++;
		}
		y++;
	}
}



int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <real_part_of_c> <imaginary_part_of_c>\n", argv[0]);
        return 1;
    }

    t_complex c;
    c.real = ft_atof(argv[1]);
    c.imag = ft_atof(argv[2]);
	t_data img;

	img.fractal = 2;
	img.c = c;
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "Julia Set");
	img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_julia(&img, c, 1.0);
    
	mlx_hook(img.win_ptr, 4, 0, handle_mouse_scroll, &img);
	mlx_hook(img.win_ptr, 2, 0, handle_key_press, &img);
	mlx_hook(img.win_ptr, 17, 0, close_window, &img);
    mlx_loop(img.mlx_ptr);

    return 0;
}
