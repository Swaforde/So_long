#include "../include/so_long.h"
#include <fcntl.h>

void	display_wall(char **map, void *mlx, void *mlx_win, t_content content)
{
	int	fd;
	char *ptr;
	int	i;
	int f;
	int posY;
	int posX;

	f = 0;
	i = 0;
	posY = 0;
	posX = 0;
	fd = open(content.map.map_path, O_RDONLY);
	while (f < content.map.height)
	{
		while (i < content.map.width)
		{
			if (map[f][i] == '1')
				mlx_put_image_to_window(mlx, mlx_win, content.image.wall, posY, posX);
			if (map[f][i] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, content.image.chad, posY, posX);
			posY += 100;
			i ++;
		}
		posY = 0;
		posX += 100;
		i = 0;
		f ++;
	}
	//ptr = get_next_line(fd);
}