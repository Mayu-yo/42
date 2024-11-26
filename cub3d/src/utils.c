/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:35:47 by mayu              #+#    #+#             */
/*   Updated: 2024/11/04 22:20:15 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void free_all(t_all_settings *settings)
// {
// }

void error_message(char *msg)
{
	printf("Error: %s\n", msg);
	// free_all();
	exit(1);
}

/* init.c */

int	check_argument(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		printf("Error: Invalid file extension\n");
		return (1);
	}
	return (0);
}

int	check_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Invalid file\n");
		return (1);
	}
	close(fd);
	return (0);
}

void init_all(t_all_settings *settings)
{
	settings->walls = ft_calloc(1, sizeof(t_walls));
	settings->walls->no = ft_calloc(1, sizeof(t_img));
	settings->walls->so = ft_calloc(1, sizeof(t_img));
	settings->walls->we = ft_calloc(1, sizeof(t_img));
	settings->walls->ea = ft_calloc(1, sizeof(t_img));
	settings->key = ft_calloc(1, sizeof(t_key));
	settings->player = ft_calloc(1, sizeof(t_player));
	settings->room = ft_calloc(1, sizeof(t_room));
	settings->room->ceiling = ft_calloc(1, sizeof(t_color));
	settings->room->floor = ft_calloc(1, sizeof(t_color));
	settings->map = NULL;
}