#include "fractal.h"

// typedef struct s_data
// {
// 	void *img;
// 	char *addr;
// 	int bits_per_pixel;
// 	int line_length;
// 	int endian;
// } t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// #define C0r -0.743 // 計算する場所の中心座標（実数部）
// #define C0i 0.1145 // 計算する場所の中心座標（虚数部）
// #define VS 0.003   // 計算する場所の中心座標からの範囲（±VS）

// #define NMAX 20000 // 計算の繰り返し上限
// #define STEP 800.0 // 計算する刻み

// double calc_mandelbrot(double a, double b)
// {
// 	double x = 0.0;
// 	double y = 0.0;
// 	double x1, y1;

// 	int n;

// 	for (n = 1; n <= NMAX; n++)
// 	{
// 		x1 = x * x - y * y + a;
// 		y1 = 2.0 * x * y + b;
// 		if (x1 * x1 + y1 * y1 > 4.0)
// 			return log(n); // 発散
// 		x = x1;
// 		y = y1;
// 	}
// 	return 0; // 計算の繰り返し上限到達
// }

// int mandelbrot()
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_data img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 700, 500, "Hello world!");
// 	img.img = mlx_new_image(mlx, 700, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								 &img.endian);
// 	// for (int x = 0; x < 50; x++)
// 	// {
// 	// 	for(int y = x * cos(M_PI / 12); y > 0; y--)
// 	// 	{
// 	// 		my_mlx_pixel_put(&img, 50 - x, y, 0x00FF0000);
// 	// 	}
// 	// }

// 	double a, b;

// 	for (a = C0r - VS; a < C0r + VS; a += 2.0 * VS / STEP)
// 	{
// 		for (b = C0i - VS; b < C0i + VS; b += 2.0 * VS / STEP)
// 		{
// 			// printf("%1.14e %1.14e %1.14e\n", a, b, mandelbrot(a, b));
// 			my_mlx_pixel_put(&img, a, b, 0x00FF0000);
// 		}
// 		// printf("\n"); // これがないとgnuplotでエラーが出る
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
// 	mlx_loop(mlx);
// }





// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

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

void init_mlx(t_mlx *mlx)
{
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
    mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
    mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &(mlx->bits_per_pixel), &(mlx->size_line), &(mlx->endian));
}

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

int find_n(t_complex c, int max_n)
{
    t_complex z = create_complex(0.0, 0.0);
    int n = 0;

    while (n < max_n && (z.real * z.real + z.imag * z.imag) < 4.0)
    {
        double temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        z.real = temp;
        n++;
    }

    return n;
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
            int n = find_n(c, max_n);
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
    int max_n = 1000;                            // Maximum number of iterations

    init_mlx(&mlx);
    draw_mandelbrot(&mlx, min_c, max_c, max_n);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
    mlx_loop(mlx.mlx_ptr);
    return 0;
}
