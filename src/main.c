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
	void	*t;
	int		width;
	int		height;
	char	relative_path = "../ressources/sprite.xpm";
	t_data	img;
	t_color color;

	color.green = 0x34eb3d;
	color.red = 0xff0000;
	color.blue = 0x0037ff;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 500, "Hello world!");
	t = mlx_xpm_file_to_image(mlx, "ressources/sprite.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, t, 0, 0);
	mlx_destroy_image(mlx, t);
	mlx_loop(mlx);
}