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
	map.width = (ft_strlen(get_next_line(fd)) - 1) * 64;
	close (fd);
	fd = open("map.txt", O_RDONLY);
	while (get_next_line(fd) != NULL)
	{
		get_next_line(fd);
		i++;
	}
	map.height = i * 64;
	close (fd);
	return (map);
}