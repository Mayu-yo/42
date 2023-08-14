/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:39:41 by mayu              #+#    #+#             */
/*   Updated: 2023/08/14 17:20:53 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

int	julia_set(int x, int y, t_complex c, double zoom)
{
	double		temp;
    int			iter;
    t_complex	z;

	iter = 0;
    z.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / zoom;
    z.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / zoom;
    while (iter < MAX_ITER && (z.real * z.real + z.imag * z.imag) < 4.0)
	{
        temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        z.real = temp;
        iter++;
    }
    return (iter);
}

int	julia_set_color(int iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

    if (iter < (MAX_ITER / 3))
	{
        t = (double)iter / (MAX_ITER / 3);
        red = (t * 0xff + (1 - t) * 0x00);
        green = (t * 0xff + (1 - t) * 0x06);
        blue = (t * 0xff + (1 - t) * 0x66);
        return (red << 16) | (green << 8) | blue;
    }
	else if (iter < MAX_ITER)
	{
        t = (double)(iter - (MAX_ITER / 3)) / (MAX_ITER * 2 / 3);
        red = (t * 0xff + (1 - t) * 0xff);
        green = (t * 0x40 + (1 - t) * 0xf7);
        blue = (t * 0x57 + (1 - t) * 0xf0);
        return (red << 16) | (green << 8) | blue;
    }
	else
        return (0);
}

void draw_julia(t_data *img, t_complex c, double zoom)
{
	int x;
	int y;
	int iter;
	int *img_data;

	y = 0;
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

int julia(int argc, char *argv[])
{
    t_complex c;
	t_data img;

    if (argc != 4)
	{
        printf("Usage: %s <real_part_of_c> <imaginary_part_of_c>\n", argv[0]);
        exit (1);
    }
    c.real = ft_atof(argv[2]);
    c.imag = ft_atof(argv[3]);
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
    exit (0);
}
