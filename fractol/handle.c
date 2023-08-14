/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:39:51 by mayu              #+#    #+#             */
/*   Updated: 2023/08/14 16:39:52 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


int	close_window(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	exit (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int handle_key_press(int keycode, t_data *data)
{
    if (keycode == 53) //ESC key
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (0);
    }
    return (0);
}

int handle_mouse_scroll(int button, int x, int y, t_data *data)
{
	static double zoom = 1.0;
    (void)x;
    (void)y;

    if (button == 4)
        zoom *= 0.9;
    else if (button == 5)
        zoom *= 1.1;

	// if (data->fractal == 1)
    	// draw_mandelbrot(data, zoom);
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	// else if (data->fractal == 2)
		draw_julia(data, data->c, zoom);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);

    return (0);
}