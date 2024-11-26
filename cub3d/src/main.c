/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:04:09 by mayu              #+#    #+#             */
/*   Updated: 2024/11/04 21:26:15 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#define WIDTH 800
#define HEIGHT 800

void mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
			&data->endian);
	mlx_hook(data->win, 2, 0, handle_key_press, &data);
	mlx_hook(data->win, 6, 0, handle_mouse_move, &data);
	mlx_hook(data->win, 17, 0, close_window, &data);
	// mlx_hook(data->win, 4, 0, handle_mouse_scroll, &data);
	mlx_loop(data->mlx);
}

void mlx_main(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 800, 600);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int main(int argc, char **argv)
{
	// char	**map;
	t_all_settings	*settings;
	t_data	*data;

	// settings = NULL;
	settings = ft_calloc(1, sizeof(t_all_settings));
	data = ft_calloc(1, sizeof(t_data));
	/* vscode debug */
	argc = 2;
	argv[1] = "./maps/testmap.cub";

	if (check_argument(argc, argv))
		return (1);
	if (check_file_exist(argv[1]))
		return (1);
	parse_cub(argv[1], settings);
	format_map(settings);
	check_map(settings);
	// printf("NO: %s\n", settings->walls->no->img);
	// printf("SO: %s\n", settings->walls->so);
	// printf("WE: %s\n", settings->walls->we);
	// printf("EA: %s\n", settings->walls->ea);
	printf("F: r:%d g:%d b:%d \n", settings->room->floor->r, settings->room->floor->g, settings->room->floor->b);
	printf("C: r:%d g:%d b:%d \n", settings->room->ceiling->r, settings->room->ceiling->g, settings->room->ceiling->b);
	while (*settings->map)
	{
		printf("%s\n", *settings->map);
		settings->map++;
	}
	mlx_setup(data);
	mlx_main(data);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q ../cub3D");
// }
