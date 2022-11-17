#include "../include/so_long.h"
#include <fcntl.h>

void	display_wall(char **map, void *mlx, void *mlx_win, t_content *content)
{
	int	fd;
	char *ptr;
	int	y;
	int x;
	int posY;
	int posX;

	y = 0;
	x = 0;
	posY = 0;
	posX = 0;
	fd = open(content->map.map_path, O_RDONLY);
	while (y < content->map.height)
	{
		while (x < content->map.width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, content->image.wall, posY, posX);
			if (map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx, mlx_win, content->image.chad, posY, posX);
				content->player.posY = y;
				content->player.posX = x;
			}
			if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, content->image.exit_s, posY, posX);
			posY += 100;
			x ++;
		}
		posY = 0;
		posX += 100;
		x = 0;
		y ++;
	}
	//ptr = get_next_line(fd);
}