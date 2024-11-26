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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_walls
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
	int		height;
	int		width;
}	t_walls;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_room
{
	t_color	*floor;
	t_color	*ceiling;
}t_room;
typedef struct s_key
{
	bool	w_pressed;
	bool	a_pressed;
	bool	s_pressed;
	bool	d_pressed;
	bool	left_pressed;
	bool	right_pressed;
}	t_key;

typedef struct s_player
{
	float	x;
	float	y;
	float	degree;
}	t_player;


typedef struct s_all_settings
{
	t_walls	*walls;
	t_key	*key;
	t_player	*player;
	t_room	*room;
	char	**map;
}	t_all_settings;

/* main.c */

/* parse_cub.c */
void parse_texture(char *line, t_all_settings *settings);
void parse_color(char *line, t_all_settings *settings);
// void parse_line(char *line, char **tmp_map);
void parse_line(char *line, char **tmp_map, t_all_settings *settings);
// int parse_cub(char *file, char ***map);
int	parse_cub(char *file, t_all_settings *settings);

/* check_map.c */
// void check_map(char **map);
void	check_map(t_all_settings *setting);
void check_map_sub(char **map, int height);
// void format_map(char ***map);
void format_map(t_all_settings *setting);

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

/* handle_mlx.c */
int close_window(int keycode, t_data *data);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int handle_key_press(int keycode, t_data *data);
int	handle_mouse_move(int x, int y, t_data *data);
// int handle_mouse_scroll(int button, int x, int y, t_data *data);

#endif