#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include "minilibx-linux/mlx.h"
#include "../gnl/get_next_line_bonus.h"

typedef struct 
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    int shift_x;
    int shift_y;
    float rotation;
    void *mlx_ptr;
    void *win_ptr;
}       fdf;

int	read_map(char *file_name);

#endif
