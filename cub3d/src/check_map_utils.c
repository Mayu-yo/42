/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:47:25 by mayu              #+#    #+#             */
/*   Updated: 2024/11/26 23:50:09 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void is_wall(char map_val)
{
	if (map_val == '1' || map_val == ' ' || map_val == '\0')
		return ;
	else
		error_message("Invalid map");
}

int is_surrounded(char **map, int i, int j)
{
	if (map[i-1][j-1] == ' ' || map[i-1][j] == ' ' || map[i-1][j+1] == ' ' ||
		map[i][j-1] == ' ' || map[i][j+1] == ' ' || map[i+1][j-1] == ' ' ||
		map[i+1][j] == ' ' || map[i+1][j+1] == ' ')
		return (1);
	return (0);
}

int is_correct_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (0);
	return (1);
}

void is_valid_player(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		error_message("Invalid map");
}
