#ifndef FDF_H
# define FDF_H

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

#endif
