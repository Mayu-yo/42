#include "fractal.h"

int handle_key_press(int keycode, t_data *data)
{
    if (keycode == 53) //ESC key
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    }
    exit (0);
}

int handle_mouse_scroll(int button, int x, int y, t_data *data)
{
	static double zoom = 1.0;
    (void)x;
    (void)y;

    if (button == 5)
        zoom *= 0.9;
    else if (button == 4)
        zoom *= 1.1;

    draw_mandelbrot(*data, zoom, 0, 0);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);

    return (0);
}