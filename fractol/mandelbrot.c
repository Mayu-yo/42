/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:39:44 by mayu              #+#    #+#             */
/*   Updated: 2023/08/14 22:27:19 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#define WIDTH 800
#define HEIGHT 800
#define MAX_REPEAT 120

int	is_mandelbrot(double a, double b)
{
	int			n;
	double		temp;
	t_complex	z;

	n = 0;
	z.real = 0;
	z.imag = 0;
	while (n < MAX_REPEAT && z.real * z.real + z.imag * z.imag < 4.0)
	{
		temp = (z.real * z.real) - (z.imag * z.imag) + a;
		z.imag = 2 * z.real * z.imag + b;
		z.real = temp;
		n++;
	}
	return (n);
}

int	mandelbrot_set_color(int n)
{
	int	red;
	int	green;
	int	blue;

	if (n == MAX_REPEAT)
		return (0x000000);
	else
	{
		red = 0x00 + (0xe0 - 0x00) * n / MAX_REPEAT;
		green = 0x19 + (0xff - 0x19) * n / MAX_REPEAT;
		blue = 0x42 + (0xfc - 0x42) * n / MAX_REPEAT;
		return ((red << 16) | (green << 8) | blue);
	}
}

void	draw_mandelbrot(t_data *img, double zoom)
{
	t_complex	c;
	int			x;
	int			y;
	int			*img_data;

	y = 0;
	img_data = (int *)mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) / WIDTH * 4 / zoom;
			c.imag = (y - HEIGHT / 2.0) / HEIGHT * 4 / zoom;
			img_data[y * WIDTH + x] = mandelbrot_set_color(
					is_mandelbrot(c.real, c.imag));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

int	mandelbrot(void)
{
	t_data	img;

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
	return (0);
}
