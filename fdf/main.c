#include <mlx.h>
#include <math.h>
#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 700, 500, "Hello world!");
	// img.img = mlx_new_image(mlx, 700, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// for (int x = 0; x < 50; x++)
	// {
	// 	for(int y = x * cos(M_PI / 12); y > 0; y--)
	// 	{
	// 		my_mlx_pixel_put(&img, 50 - x, y, 0x00FF0000);
	// 	}
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
	// mlx_loop(mlx);
	if (argc != 2)
		exit(1);

	if(read_map(argv[1]) == -1)
		exit(1);
}