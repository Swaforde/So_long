/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/12/19 13:10:17 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>

int	ft_get_height(t_map map)
{
	int	height;
	int	fd;
	char	*line;

	fd = open(map.map_path, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	free (line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		height ++;
		free (line);
	}
	close (fd);
	return (height);
}

int	ft_get_width(t_map map)
{
	int		width;
	int		fd;
	char	*ptr;
	char	*line;

	width = 0;
	fd = open(map.map_path, O_RDONLY);
	line = get_next_line(fd);
	ptr = ft_strdup(line);
	free (line);
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
				content->player.posy = y;
				content->player.posx = x;
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
	char	*line;

	i = 0;
	fd = open(map.map_path, O_RDONLY);
	while (i < map.height)
	{
		line = get_next_line(fd);
		tmp = ft_strdup(line);
		free (line);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		tab[i] = ft_strdup(tmp);
		i ++;
		free (tmp);
	}
	close (fd);
}
