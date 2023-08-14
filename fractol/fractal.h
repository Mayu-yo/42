/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:09:35 by vmuradia          #+#    #+#             */
/*   Updated: 2023/08/14 17:18:29 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

typedef struct	s_data {
	int		fractal;
	void 	*mlx_ptr;
    void 	*win_ptr;
	t_complex c;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		handle_key_press(int keycode, t_data *data);
int		handle_mouse_scroll(int button, int x, int y, t_data *data);
void	draw_mandelbrot(t_data *img, double zoom);
double	ft_atof(char *num);
int		close_window(int keycode, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_julia(t_data *img, t_complex c, double zoom);
int julia(int argc, char *argv[]);
int mandelbrot(void);

#endif
