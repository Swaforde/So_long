#include "../include/so_long.h"
#include <fcntl.h>

void	put_images(t_content content, int posY, int posX, char c)
{
	void	*wall;
	void	*chad;
	void	*erase;
	int		tmp1;
	int		tmp2;

	wall = mlx_xpm_file_to_image(content.mlx, "./ressources/wall.xpm", &tmp1, &tmp2);
	chad = mlx_xpm_file_to_image(content.mlx, "./ressources/chad.xpm", &tmp1, &tmp2);
	erase = mlx_xpm_file_to_image(content.mlx, "./ressources/erase.xpm", &tmp1, &tmp2);
	if (c == '1')
		mlx_put_image_to_window(content.mlx, content.mlx_win, wall, posY, posX);
	if (c == 'P')
		mlx_put_image_to_window(content.mlx, content.mlx_win, chad, posY, posX);
	if (c == '0')
		mlx_put_image_to_window(content.mlx, content.mlx_win, erase, posY, posX);
}

void	update(t_content content)
{
	int		i;
	int		f;
	int		posX;
	int		posY;

	i = 0;
	f = 0;
	posX = 0;
	posY = 0;
	while (i < content.map.height)
	{
		while (f < content.map.width)
		{
			put_images(content, posY, posX, content.tab[i][f]);
			posY += 100;
			f ++;
		}
		ft_printf("%s", content.tab[i]);
		posY = 0;
		posX += 100;
		f = 0;
		i ++;
	}
}