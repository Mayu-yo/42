/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:09:35 by vmuradia          #+#    #+#             */
/*   Updated: 2023/08/04 17:18:06 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct	s_data {
	void *mlx_ptr;
    void *win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int handle_key_press(int keycode, t_data *data);
int handle_mouse_scroll(int button, int x, int y, t_data *data);
void draw_mandelbrot(t_data img, double zoom);
double ft_atof(char *num);
int	close_window(int keycode, t_data *data);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
