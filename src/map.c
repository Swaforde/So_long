#include "../include/so_long.h"
#include <fcntl.h>

t_map   map_info(void)
{
	t_map	map;
	int		i;
	int		fd;
	int		fd2;
	
	i = 1;
	fd = open("map.txt", O_RDONLY);
	map.width = (ft_strlen(get_next_line(fd)) - 1);
	close (fd);
	fd = open("map.txt", O_RDONLY);
	while (get_next_line(fd) != NULL)
	{
		get_next_line(fd);
		i++;
	}
	map.height = i;
	close (fd);
	return (map);
}

void map_parsing(char **tab)
{
	int		height;
	int		width;
	int		i;
	int		fd;

	i = 0;
	fd = open("map.txt", O_RDONLY);
	height = map_info().height;
	width = map_info().width;
	while (i <= height)
		tab[i ++] = ft_strdup(get_next_line(fd));
}