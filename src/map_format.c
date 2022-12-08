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
			if (map[i][f] != 'P' && map[i][f] != 'E' && map[i][f] != '1' && map[i][f] != '0' && map[i][f] != 'C')
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
	int score;

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
	return  (1);
}

int	map_format_checker(char **map, t_map info)
{
	if (extension_checker(info) != 1)
	{
		ft_printf(" Error\nL'extension de fichier est invalide !");
		return (0);
	}
	if (lenght_checker(map, info) != 1)
	{
		ft_printf("Error\nLa map ne correspond pas au format !");
		return (0);
	}
	if (doublon_checker(map, info, 'P') > 1)
	{
		ft_printf("Error\nLa map contient trop de giga chad ! (player)");
		return (0);
	}
	if (doublon_checker(map, info, 'P') < 1)
	{
		ft_printf("Error\nLa map ne contient aucun player");
		return (0);
	}
	if (doublon_checker(map, info, 'E') > 1)
	{
		ft_printf("Error\nLa map contient trop plusieurs sorties !");
		return (0);
	}
	if (doublon_checker(map, info, 'E') < 1)
	{
		ft_printf("Error\nLa map ne contient aucune sortie !");
		return (0);
	}
	if (char_checker(map, info) != 1)
	{
		ft_printf("Error\nLa map contient des charactère interdit !");
		return (0);
	}
	return (1);
}