/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:04:09 by mayu              #+#    #+#             */
/*   Updated: 2024/10/07 17:40:01 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	/* vscode debug */
	argc = 2;
	argv[1] = "./maps/testmap.cub";

	if (check_argument(argc, argv))
		return (1);
	if (check_file_exist(argv[1]))
		return (1);
	parse_cub(argv[1], &map);
	format_map(&map);
	check_map(map);
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
	while (1)
		;
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q ../cub3D");
// }
