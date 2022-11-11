#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_color color;

	color.green = 0x34eb3d;
	color.red = 0xff0000;
	color.blue = 0x0037ff;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_info().width, map_info().height, "Hello world!");
	mlx_loop(mlx);
}