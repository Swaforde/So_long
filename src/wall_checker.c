/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:05 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	wall_checker_extra(char *line, t_map info)
{
	int	i;

	i = 0;
	while (i < info.width)
	{
		if (line[i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

int	wall_checker_intra(char *line, t_map info)
{
	if (line[0] != '1' || line[info.width - 1] != '1')
		return (0);
	return (1);
}

int	custom_return(char *buffer)
{
	free (buffer);
	ft_printf("La carte n'est pas fermée !");
	return (0);
}

int	wall_checker(char **map, t_map info)
{
	char	*buffer;
	int		i;

	i = 0;
	while (i < info.height)
	{
		buffer = ft_strdup(map[i]);
		if (i == 0 || i == (info.height - 1))
		{
			if (wall_checker_extra(buffer, info) != 1)
				return (custom_return(buffer));
		}
		else
		{
			if (wall_checker_intra(buffer, info) != 1)
				return (custom_return(buffer));
		}
		i ++;
		free (buffer);
	}
	return (1);
}
