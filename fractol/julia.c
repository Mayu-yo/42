#include "fractal.h"

#define WIDTH 800
#define HEIGHT 800
#define MAX_REPEAT 100
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	close_window(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

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
        return 0x000000; // Black for points that don't diverge
    else
        return (n * 255 / MAX_REPEAT) << 16 | (n * 255 / MAX_REPEAT) << 8 | n * 255 / MAX_REPEAT; // Color gradient based on the iteration count
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double a;
	double b;
	int x,y = 0;
	int n;

	n = 0;
	a = -2.0;
	b = -2.0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while(a <= 2.0){
		while(b <= 2.0){
			n = is_mandelbrot(a, b);
				my_mlx_pixel_put(&img, (a + 2) * 200, (b + 2) * 200, mandelbrot_set_color(n));
			b = b + 0.005;
		}
		b = -2.0;
		a = a + 0.005;
	}

	// while(x < WIDTH){
	// 	while(y < HEIGHT){
	// 		a = -2.0 + (3.0) * x / WIDTH;
	// 		b = -1.5 + (3.0) * y / HEIGHT;
	// 		n = is_mandelbrot(a, b);
	// 			my_mlx_pixel_put(&img, x, y, mandelbrot_set_color(n));
	// 		y++;
	// 	}
	// 	y = 0;
	// 	x++;
	// }
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 1L << 17, close_window, &img);
	mlx_loop(mlx);
}
