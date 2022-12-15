/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:05 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	char_checker(char **map, t_map info)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (i < info.height)
	{
		while (f < info.width)
		{
			if (map[i][f] != 'P' && map[i][f] != 'E' && map[i][f] != '1'
				&& map[i][f] != '0' && map[i][f] != 'C')
				return (0);
			f ++;
		}
		f = 0;
		i ++;
	}
	return (1);
}

int	doublon_checker(char **map, t_map info, char c)
{
	int	i;
	int	f;
	int	score;

	i = 0;
	f = 0;
	score = 0;
	while (i < info.height)
	{
		while (f < info.width)
		{
			if (map[i][f] == c)
				score ++;
			f ++;
		}
		f = 0;
		i ++;
	}
	return (score);
}

int	lenght_checker(char **map, t_map info)
{
	int		i;
	char	*buffer;

	i = 0;
	while (i < info.height)
	{
		buffer = ft_strdup(map[i]);
		if (ft_strlen(map[i]) != info.width)
		{
			free (buffer);
			return (0);
		}
		i ++;
		free (buffer);
	}
	return (1);
}

int	extension_checker(t_map info)
{
	int	i;

	i = ft_strlen(info.map_path);
	i --;
	if (info.map_path[i] != 'r')
		return (0);
	i --;
	if (info.map_path[i] != 'e')
		return (0);
	i --;
	if (info.map_path[i] != 'b')
		return (0);
	i --;
	if (info.map_path[i] != '.')
		return (0);
	return (1);
}

int	map_format_checker(char **map, t_map info)
{
	if (extension_checker(info) != 1)
		return (1);
	if (lenght_checker(map, info) != 1)
		return (2);
	if (doublon_checker(map, info, 'P') > 1)
		return (3);
	if (doublon_checker(map, info, 'P') < 1)
		return (4);
	if (doublon_checker(map, info, 'E') > 1)
		return (5);
	if (doublon_checker(map, info, 'E') < 1)
		return (6);
	if (char_checker(map, info) != 1)
		return (7);
	return (8);
}
