#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include "../GNL/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_color
{
	int	green;
	int	red;
	int	blue;
}		t_color;

typedef struct s_map
{
	int		width;
	int		height;
	char	*map_path;
}		t_map;

typedef struct s_content
{
	t_map	map;
	char	**tab;
	void	*mlx;
	void	*mlx_win;
}		t_content;

enum	key
{
	w = 13,
	a = 0,
	s = 1,
	d = 2
};

int		ft_get_height(t_map);
int		ft_get_width(t_map map);
void	map_parsing(char **tab, t_map map);
void	display_wall(char **map, void *mlx, void *mlx_win, t_map data);
int		wall_checker(char **map, t_map info);
int		map_format_checker(char **map, t_map info);
void	update(t_content content);

#endif