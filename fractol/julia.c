
#include "fractal.h"
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

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

int julia_set_color(int iter)
{
    int color;
    int pixel_color;

    if (iter < (MAX_ITER/3)) {
        double t = (double)iter / (MAX_ITER/3);
        int red = (int)(t * 0xff + (1 - t) * 0x00);
        int green = (int)(t * 0xff + (1 - t) * 0x06);
        int blue = (int)(t * 0xff + (1 - t) * 0x66);
        return (red << 16) | (green << 8) | blue;
    } else if (iter < MAX_ITER) {
        double t = (double)(iter-(MAX_ITER/3)) / (MAX_ITER * 2 / 3);
        int red = (int)(t * 0xff + (1 - t) * 0xff);
        int green = (int)(t * 0x40 + (1 - t) * 0xf7);
        int blue = (int)(t * 0x57 + (1 - t) * 0xf0);
        return (red << 16) | (green << 8) | blue;
    } else {
        color = 0;
        pixel_color = (color << 16) | (color << 8) | color;
    }
    return (pixel_color);
}

void draw_julia(t_data *img, t_complex c, double zoom)
{
	int x = 0;
	int y = 0;
	int iter = 0;
	int *img_data;

	img_data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
										&img->endian);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = julia_set(x, y, c, zoom);
			img_data[y * WIDTH + x] = julia_set_color(iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <real_part_of_c> <imaginary_part_of_c>\n", argv[0]);
        exit (1);
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
