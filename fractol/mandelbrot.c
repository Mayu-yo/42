#include "fractal.h"

#define WIDTH 800
#define HEIGHT 800
#define MAX_REPEAT 100

int is_mandelbrot(double a, double b){
	int n;
	double zr;
	double zi;
	double temp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_REPEAT && zr * zr + zi * zi < 4.0){
		temp = (zr * zr) - (zi * zi) + a;
		zi = 2 * zr * zi + b;
		zr = temp;
		n++;
	}
	return (n);
}

int mandelbrot_set_color(int n)
{
    if (n == MAX_REPEAT)
        return 0x000000;
    else {
        int red = 0x00 + (int)((0xe0 - 0x00) * (double)n / MAX_REPEAT);
        int green = 0x19 + (int)((0xff - 0x19) * (double)n / MAX_REPEAT);
        int blue = 0x42 + (int)((0xfc - 0x42) * (double)n / MAX_REPEAT);

        return (red << 16) | (green << 8) | blue;
    }
}

void draw_mandelbrot(t_data *img, double zoom){
	double a = -2.0;
	double b = -2.0;
	int x,y = 0;
	int n;
	int *img_data;

	img_data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
										&img->endian);
	n = 0;
	while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH) {
            a = (x - WIDTH / 2.0) / WIDTH * 4 / zoom;
            b = (y - HEIGHT / 2.0) / HEIGHT * 4 / zoom;
            n = is_mandelbrot(a, b);
			img_data[y * WIDTH + x] = mandelbrot_set_color(n);
            x++;
        }
        y++;
    }
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

int main(void)
{
	t_data img;

	img.fractal = 1;
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
	img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_mandelbrot(&img, 1.0);
	mlx_hook(img.win_ptr, 2, 0, handle_key_press, &img);
	mlx_hook(img.win_ptr, 17, 0, close_window, &img);
	mlx_hook(img.win_ptr, 4, 0, handle_mouse_scroll, &img);
	mlx_loop(img.mlx_ptr);
	// mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);

	return (0);
}
