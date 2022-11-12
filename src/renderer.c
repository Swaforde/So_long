#include "../include/so_long.h"
#include <fcntl.h>

void	display_wall(char **map, void *mlx, void *mlx_win, t_map data)
{
	int	fd;
	int	width;
	int height;
	void *img;
	char *ptr;
	int	i;
	int f;
	int posY;
	int posX;

	f = 0;
	i = 0;
	posY = 0;
	posX = 0;
	fd = open("map.txt", O_RDONLY);
	img = mlx_xpm_file_to_image(mlx, "./ressources/wall.xpm", &width, &height);
	while (f < data.height)
	{
		while (i < data.width)
		{
			if (map[f][i] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img, posY, posX);
			posY += 100;
			i ++;
		}
		posY = 0;
		posX += 100;
		i = 0;
		f ++;
	}
	ptr = get_next_line(fd);
}