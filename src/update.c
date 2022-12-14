#include "../include/so_long.h"
#include <fcntl.h>

void	put_images(t_content *c, int p_y, int p_x, char tested_char)
{
	if (tested_char == '1')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->image.wall, p_y, p_x);
	if (tested_char == 'P')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->image.chad, p_y, p_x);
	if (tested_char == '0')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->image.erase, p_y, p_x);
	if (tested_char == 'E')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->image.exit_s, p_y, p_x);
	if (tested_char == 'C')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->image.coin, p_y, p_x);
}

void	update(t_content *content)
{
	int		i;
	int		f;
	int		p_x;
	int		p_y;

	i = 0;
	f = 0;
	p_x = 0;
	p_y = 0;
	while (i < content->map.height)
	{
		while (f < content->map.width)
		{
			put_images(content, p_y, p_x, content->tab[i][f]);
			p_y += 50;
			f ++;
		}
		p_y = 0;
		p_x += 50;
		f = 0;
		i ++;
	}
}
