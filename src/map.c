#include "../include/so_long.h"
#include <fcntl.h>

int	ft_get_height(t_map map)
{
	int height;
	int	fd;

	fd = open(map.map_path, O_RDONLY);
	height = 0;

	while (get_next_line(fd) != NULL)
		height ++;
	close (fd);
	return (height);
}

int	ft_get_width(t_map map)
{
	int	width;
	int	fd;
	char	*ptr;

	width = 0;
	fd = open(map.map_path, O_RDONLY);
	ptr = ft_strdup(get_next_line(fd));
	close (fd);
	width = ft_strlen(ptr);
	if (ptr[ft_strlen(ptr) - 1] == '\n')
		width --;
	free (ptr);
	return (width);
}

void map_parsing(char **tab, t_map map)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(map.map_path, O_RDONLY);
	while (i < map.height)
	{
		tmp = ft_strdup(get_next_line(fd));
		if (tmp[ft_strlen(tmp) -1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		tab[i] = ft_strdup(tmp);
		i ++;
		free (tmp);
	}
	close (fd);
}