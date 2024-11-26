/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:37:35 by mayu              #+#    #+#             */
/*   Updated: 2024/11/04 23:17:41 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void parse_texture(char *line, t_all_settings *settings)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
		i++;
	printf("%s\n", split[1]);
	if (i != 2)
		error_message("Invalid texture");
	if (ft_strncmp(split[0], "NO", 2) == 0)
		settings->walls->no->img = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		settings->walls->so->img = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		settings->walls->we->img = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		settings->walls->ea->img = ft_strdup(split[1]);
	// printf("Texture: %s\n", line);
}

void parse_color(char *line, t_all_settings *settings)
{
	char	**split;
	int		i;
	int		j;
	t_color	*room_ptr;
	
	room_ptr = NULL;
	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
		i++;
	if (i != 2)
		error_message("Invalid color");
	j = 0;
	while (split[1][j])
	{
		if (!ft_isdigit(split[1][j]) && split[1][j] != ',')
			error_message("Invalid color");
		j++;
	}
	if (ft_strncmp(split[0], "F", 1) == 0)
		room_ptr = settings->room->floor;
	else if (ft_strncmp(split[0], "C", 1) == 0)
		room_ptr = settings->room->ceiling;
	room_ptr->r = ft_atoi(split[1]);
	
	
		settings->room->floor->r = ft_atoi(&split[1][0]);
		settings->room->floor->g = ft_atoi(&split[1][1]);
		settings->room->floor->b = ft_atoi(&split[1][2]);

	// printf("Color: %s\n", line);
}

void parse_line(char *line, char **tmp_map, t_all_settings *settings)
{
	printf("line: %s\n", line);
	printf("%d\n", ft_strncmp(line, "NO ", 3));
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_texture(line, settings);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_texture(line, settings);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_texture(line, settings);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_texture(line, settings);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_color(line, settings);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_color(line, settings);
	else if (ft_strncmp(line, " ", 1) == 0 || ft_strncmp(line, "1", 1) == 0)
		*tmp_map = ft_strjoin(*tmp_map, line);
	else if (ft_strncmp(line, "\n", 1) == 0)
		return ;
	else
		error_message("Invalid file");
}

int	parse_cub(char *file, t_all_settings *settings)
{
	int	fd;
	char	*line;
	char	*tmp_map;

	tmp_map = NULL;
	printf("file: %s\n", file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_message("Invalid file");
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, &tmp_map, settings);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	//if 要素が足りなかったらエラー
	if (!tmp_map)
		error_message("Invalid file");
	settings->map = ft_split(tmp_map, '\n');
	free(tmp_map);
	return (0);
}
