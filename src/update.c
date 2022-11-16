#include "../include/so_long.h"
#include <fcntl.h>

void	put_images(t_content *content, int posY, int posX, char c)
{
	if (c == '1')
		mlx_put_image_to_window(content->mlx, content->mlx_win, content->image.wall, posY, posX);
	if (c == 'P')
		mlx_put_image_to_window(content->mlx, content->mlx_win, content->image.chad, posY, posX);
	if (c == '0')
		mlx_put_image_to_window(content->mlx, content->mlx_win, content->image.erase, posY, posX);
}

void	update(t_content *content)
{
	int		i;
	int		f;
	int		posX;
	int		posY;

	i = 0;
	f = 0;
	posX = 0;
	posY = 0;
	while (i < content->map.height)
	{
		while (f < content->map.width)
		{
			put_images(content, posY, posX, content->tab[i][f]);
			posY += 100;
			f ++;
		}
		posY = 0;
		posX += 100;
		f = 0;
		i ++;
	}
}