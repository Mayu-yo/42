/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:37:35 by mayu              #+#    #+#             */
/*   Updated: 2024/10/07 17:48:38 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void parse_texture(char *line)
{
	// char	**split;
	// int		i;

	// split = ft_split(line, ' ');
	// i = 0;
	// while (split[i])
	// 	i++;
	// if (i != 2)
	// 	error_message("Invalid texture");
	printf("Texture: %s\n", line);
}

void parse_color(char *line)
{
	// char	**split;
	// int		i;

	// split = ft_split(line, ' ');
	// i = 0;
	// while (split[i])
	// 	i++;
	// if (i != 2)
	// 	error_message("Invalid color");
	printf("Color: %s\n", line);
}

void parse_line(char *line, char **tmp_map)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_texture(line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_texture(line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_texture(line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_texture(line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_color(line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_color(line);
	else if (ft_strncmp(line, " ", 1) == 0 || ft_strncmp(line, "1", 1) == 0)
		*tmp_map = ft_strjoin(*tmp_map, line);
	else if (ft_strncmp(line, "\n", 1) == 0)
		return ;
	else
		error_message("Invalid file");
}

int	parse_cub(char *file, char ***map)
{
	int	fd;
	char	*line;
	char	*tmp_map;

	tmp_map = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_message("Invalid file");
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, &tmp_map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	//if 要素が足りなかったらエラー
	if (!tmp_map)
		error_message("Invalid file");
	*map = ft_split(tmp_map, '\n');
	free(tmp_map);
	return (0);
}
