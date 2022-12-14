#include "../include/so_long.h"
#include <fcntl.h>

int	ft_get_height(t_map map)
{
	int	height;
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
	int		width;
	int		fd;
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

int	get_max_score(char **tab, t_map map)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while (y < map.height)
	{
		while (x < map.width)
		{
			if (tab[y][x] == 'C')
				i ++;
			x ++;
		}
		x = 0;
		y ++;
	}
	return (i);
}

void	get_start_position(t_content *content)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < content->map.height)
	{
		while (x < content->map.width)
		{
			if (content->tab[y][x] == 'P')
			{
				content->player.posY = y;
				content->player.posX = x;
			}
			x ++;
		}
		x = 0;
		y ++;
	}
}

void	map_parsing(char **tab, t_map map)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(map.map_path, O_RDONLY);
	while (i < map.height)
	{
		tmp = ft_strdup(get_next_line(fd));
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		tab[i] = ft_strdup(tmp);
		i ++;
		free (tmp);
	}
	close (fd);
}
