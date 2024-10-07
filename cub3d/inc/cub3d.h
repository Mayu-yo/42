#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <../minilibx/mlx.h>
# include <math.h>

# include "libft.h"

/* main.c */

/* parse_cub.c */
void parse_texture(char *line);
void parse_color(char *line);
void parse_line(char *line, char **tmp_map);
int parse_cub(char *file, char ***map);

/* check_map.c */
void check_map(char **map);
void check_map_sub(char **map, int height);
void format_map(char ***map);

/* check_map_utils.c */
void is_valid_player(char **map);
void is_wall(char c);
int is_surrounded(char **map, int i, int j);
int is_correct_char(char c);

/* utils.c */
void error_message(char *msg);
int check_argument(int argc, char **argv);
int check_file_exist(char *file);
// void free_all();

#endif