#include "fractal.h"

#define WIDTH 800
#define HEIGHT 800
#define MAX_REPEAT 100


int	close_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int is_mandelbrot(double a, double b){
	int n;
	double zr;
	double zi;
	double temp;

	n = 1;
	zr = 0;
	zi = 0;
	while (n < MAX_REPEAT){
		temp = pow(zr, 2) - pow(zi, 2) + a;
		zi = 2 * zr * zi + b;
		zr = temp;
		if (pow(zr, 2) + pow(zi, 2) >= 4)
			break;
		n++;
	}
	return (n);
}

int mandelbrot_set_color(int n)
{
    if (n == MAX_REPEAT)
        return 0x000000;
    else
        return (n * 255 / MAX_REPEAT) << 16 | (n * 255 / MAX_REPEAT) << 8 | n * 255 / MAX_REPEAT; // Color gradient based on the iteration count
}

void draw_mandelbrot(t_data img, double zoom, double center_x, double center_y){//center_x,yは消す
	double a = -2.0;
	double b = -2.0;
	double x,y = 0;
	int n;

	n = 0;
	while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH) {
            a = center_x + (x - WIDTH / 2.0) / WIDTH * 4 / zoom;
            b = center_y + (y - HEIGHT / 2.0) / HEIGHT * 4 / zoom;
            n = is_mandelbrot(a, b);
            my_mlx_pixel_put(&img, x, y, mandelbrot_set_color(n));
            x++;
        }
        y++;
    }
}

int main(void)
{
	t_data img;

	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
	img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_mandelbrot(img, 1.0, 0, 0);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_hook(img.win_ptr, 4, 0, handle_mouse_scroll, &img);
	mlx_hook(img.win_ptr, 2, 0, handle_key_press, &img);
	mlx_hook(img.win_ptr, 17, 0, close_window, &img);
	mlx_loop(img.mlx_ptr);
	return (0);
}
