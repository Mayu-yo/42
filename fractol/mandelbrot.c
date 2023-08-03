#include "fractal.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int bits_per_pixel;
    int size_line;
    int endian;
} t_mlx;

typedef struct s_complex
{
    double real;
    double imag;
} t_complex;

// void init_mlx(t_mlx *mlx)
// {
//     mlx->mlx_ptr = mlx_init();
//     mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
//     mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
//     mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &(mlx->bits_per_pixel), &(mlx->size_line), &(mlx->endian));
// }

t_complex create_complex(double real, double imag)
{
    t_complex c;
    c.real = real;
    c.imag = imag;
    return c;
}

int mandelbrot_set_color(int n, int max_n)
{
    if (n == max_n)
        return 0x000000; // Black for points that don't diverge
    else
        return (n * 255 / max_n) << 16 | (n * 255 / max_n) << 8 | n * 255 / max_n; // Color gradient based on the iteration count
}

// int find_n(t_complex c, int max_n)
int find_n(double a, double b, int max_n)
{
    t_complex z = create_complex(0.0, 0.0);
    int n = 0;

    while (n < max_n && (z.real * z.real + z.imag * z.imag) < 4.0)
    {
        // double temp = z.real * z.real - z.imag * z.imag + a;
        z.imag = 2.0 * z.real * z.imag + b;
        z.real = z.real * z.real - z.imag * z.imag + a;
        n++;
    }

    // return n;
	// int n;
	// double zr;
	// double zi;

	// n = 1;
	// zr = 0;
	// zi = 0;
	// while (n < max_n){
	// 	zr = pow(zr, 2) - pow(zi, 2) + a;
	// 	zi = 2 * zr * zi + b;
	// 	if (pow(zr, 2) + pow(zi, 2) >= 4)
	// 		break;
	// 	n++;
	// }
	return (n);
}

void draw_mandelbrot(t_mlx *mlx, t_complex min_c, t_complex max_c, int max_n)
{
    int x, y;

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            double a = min_c.real + (max_c.real - min_c.real) * x / WIDTH;
            double b = min_c.imag + (max_c.imag - min_c.imag) * y / HEIGHT;
            t_complex c = create_complex(a, b);
            int n = find_n(c.real, c.imag, max_n);
            int color = mandelbrot_set_color(n, max_n);
            *(int *)(mlx->img_data + (y * mlx->size_line + x * mlx->bits_per_pixel / 8)) = color;
        }
    }
}

int main()
{
    t_mlx mlx;
    t_complex min_c = create_complex(-2.0, -1.5); // Minimum complex number of the view
    t_complex max_c = create_complex(1.0, 1.5);   // Maximum complex number of the view
    int max_n = 100;                            // Maximum number of iterations

    // init_mlx(&mlx);
	mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
    mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
    mlx.img_data = mlx_get_data_addr(mlx.img_ptr, &(mlx.bits_per_pixel), &(mlx.size_line), &(mlx.endian));
    draw_mandelbrot(&mlx, min_c, max_c, max_n);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
    mlx_loop(mlx.mlx_ptr);
    return 0;
}
