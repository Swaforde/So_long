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
	int		i;

	i = 0;
	t_map	map;
	t_data	img;
	t_color color;

	color.green = 0x34eb3d;
	color.red = 0xff0000;
	color.blue = 0x0037ff;
	map.height = ft_get_height();
	map.width = ft_get_width();

	tab = ft_calloc (sizeof(char *), (map.height + 1));
	*tab = ft_calloc (sizeof(char), (map.width + 1));
	map_parsing(tab, map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.width * 100, map.height * 100, "Hello world!");
	display_wall(tab, mlx, mlx_win, map);
	mlx_loop(mlx);
}