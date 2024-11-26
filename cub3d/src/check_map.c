/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:39:55 by mayu              #+#    #+#             */
/*   Updated: 2024/10/14 16:58:34 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void check_map_sub(char **map, int height)
{
	int i;
	int j;
	i = 1;
	while (i < height)
	{
		is_wall(map[i][0]);
		j = 1;
		while (map[i][j])
		{
			if (is_surrounded(map, i, j))
				is_wall(map[i][j]);
			else
			{
				if (is_correct_char(map[i][j]))
					error_message("Invalid map");
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_all_settings *setting)
{
	int j;
	int height;
	char **map;

	height = 0;
	map = setting->map;
	while (map[height])
		height++;
	height--;
	j = 0;
	while (map[0][j++])
		is_wall(map[0][j]);
	j = 0;
	while (map[height][j++])
		is_wall(map[height][j]);
	is_valid_player(map);
	check_map_sub(map, height);
}

void format_map(t_all_settings *setting)
{
	int i;
	int len;
	int max_len;
	char **map;

	i = 0;
	max_len = 0;
	map = setting->map;
	while ((map)[i])
	{
		len = strlen((map)[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	i = 0;
	while ((map)[i])
	{
		len = strlen((map)[i]);
		while (len < max_len)
		{
			(map)[i] = ft_strjoin((map)[i], " ");
			len++;
		}
		i++;
	}
}
