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
	char	**tab;
	t_data	img;
	t_color color;

	color.green = 0x34eb3d;
	color.red = 0xff0000;
	color.blue = 0x0037ff;
	tab = ft_calloc (sizeof(char *), (map_info().width + 1));
	*tab = ft_calloc (sizeof(char), (map_info().height + 1));
	map_parsing(tab);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_info().width * 100, map_info().height * 100, "Hello world!");
	ft_printf ("%c", tab[0][10]);
	mlx_loop(mlx);
}