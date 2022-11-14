#include "../include/so_long.h"

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

int	map_format_checker(char **map, t_map info)
{
	if (lenght_checker(map, info) != 1)
	{
		ft_printf("La map ne correspond pas au format !");
		return (0);
	}
	return (1);
}