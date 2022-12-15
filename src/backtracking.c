/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c        	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:05 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	backtracking(int posY, int posX, t_content *content)
{
	if (content->tabTest[posY - 1][posX] != '1')
	{
		content->tabTest[posY][posX] = '1';
		backtracking(posY - 1, posX, content);
	}
	if (content->tabTest[posY][posX + 1] != '1')
	{
		content->tabTest[posY][posX] = '1';
		backtracking(posY, posX + 1, content);
	}
	if (content->tabTest[posY + 1][posX] != '1')
	{
		content->tabTest[posY][posX] = '1';
		backtracking(posY + 1, posX, content);
	}
	if (content->tabTest[posY][posX - 1] != '1')
	{
		content->tabTest[posY][posX] = '1';
		backtracking(posY, posX - 1, content);
	}
	content->tabTest[posY][posX] = '1';
}

int	check_all_element(t_content *content, char **tab)
{
	int	i;
	int	f;
	int	total;

	i = 0;
	f = 0;
	total = 0;
	while (i < content->map.height)
	{
		while (f < content->map.width)
		{
			if (tab[i][f] == 'C' || tab[i][f] == 'E')
				total ++;
			f ++;
		}
		f = 0;
		i ++;
	}
	if (total != 0)
		ft_printf("Error\nTous les objets ne sont pas collectable !");
	return (total);
}
