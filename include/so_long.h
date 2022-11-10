#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_color
{
	int green;
	int red;
	int blue;
}		t_color;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    ft_draw_rec(t_data data, int posX, int posY, int w, int h, int color);

#endif