#include "../include/so_long.h"

int wall_checker(char **map, t_map info)
{
	int f;
	int i;

	f = 1;
	i = 0;

	while (i < info.width)
	{
		if (map[0][i] != 1)
			f = 0;
		i ++;
	}
	return (i);
}

int map_checker(char **map, t_map info)
{
	int	i;

	i = 0;
	ft_printf("%d", wall_checker(map, info));
	return (i);
}
