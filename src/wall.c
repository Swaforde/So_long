#include "../include/so_long.h"
#include <fcntl.h>

void	display_wall(char **map)
{
	int	fd;
	char *ptr;

	fd = open("map.txt", O_RDONLY);
	ptr = get_next_line(fd);
}