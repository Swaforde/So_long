/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/12/16 10:30:49 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>

int	collectable_check(int movement, t_content *cont)
{
	if (movement == 0)
	{
		if (cont->tab[cont->player.posy - 1][cont->player.posx] == 'C')
			return (1);
	}
	if (movement == 1)
	{
		if (cont->tab[cont->player.posy][cont->player.posx + 1] == 'C')
			return (1);
	}
	if (movement == 2)
	{
		if (cont->tab[cont->player.posy + 1][cont->player.posx] == 'C')
			return (1);
	}
	if (movement == 3)
	{
		if (cont->tab[cont->player.posy][cont->player.posx - 1] == 'C')
			return (1);
	}
	return (0);
}

int	forward(t_content *cont, int mod)
{
	if (cont->tab[cont->player.posy - 1][cont->player.posx] != '1')
	{
		cont->player.score += collectable_check(0, cont);
		if (cont->tab[cont->player.posy - 1][cont->player.posx] == 'E')
		{
			if (exit_func(cont, cont->player.posy - 1, cont->player.posx) == 0)
			{
				cont->exit.y = cont->player.posy - 1;
				cont->exit.x = cont->player.posx;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			reset_value(cont);
		}
		else
			cont->tab[cont->player.posy][cont->player.posx] = '0';
		cont->player.posy --;
		cont->tab[cont->player.posy][cont->player.posx] = 'P';
	}
	else
		return (0);
	return (1);
}

int	backward(t_content *cont, int mod)
{
	if (cont->tab[cont->player.posy + 1][cont->player.posx] != '1')
	{
		cont->player.score += collectable_check(2, cont);
		if (cont->tab[cont->player.posy + 1][cont->player.posx] == 'E')
		{
			if (exit_func(cont, cont->player.posy + 1, cont->player.posx) == 0)
			{
				cont->exit.y = cont->player.posy + 1;
				cont->exit.x = cont->player.posx;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			reset_value(cont);
		}
		else
			cont->tab[cont->player.posy][cont->player.posx] = '0';
		cont->player.posy ++;
		cont->tab[cont->player.posy][cont->player.posx] = 'P';
	}
	else
		return (0);
	return (1);
}

int	turn_right(t_content *cont, int mod)
{
	if (cont->tab[cont->player.posy][cont->player.posx + 1] != '1')
	{
		cont->player.score += collectable_check(1, cont);
		if (cont->tab[cont->player.posy][cont->player.posx + 1] == 'E')
		{
			if (exit_func(cont, cont->player.posy, cont->player.posx + 1) == 0)
			{
				cont->exit.y = cont->player.posy;
				cont->exit.x = cont->player.posx + 1;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			reset_value(cont);
		}
		else
			cont->tab[cont->player.posy][cont->player.posx] = '0';
		cont->player.posx ++;
		cont->tab[cont->player.posy][cont->player.posx] = 'P';
	}
	else
		return (0);
	return (1);
}

int	turn_left(t_content *cont, int mod)
{
	if (cont->tab[cont->player.posy][cont->player.posx - 1] != '1')
	{
		cont->player.score += collectable_check(3, cont);
		if (cont->tab[cont->player.posy][cont->player.posx - 1] == 'E')
		{
			if (exit_func(cont, cont->player.posy, cont->player.posx - 1) == 0)
			{
				cont->exit.y = cont->player.posy;
				cont->exit.x = cont->player.posx - 1;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			reset_value(cont);
		}
		else
			cont->tab[cont->player.posy][cont->player.posx] = '0';
		cont->player.posx --;
		cont->tab[cont->player.posy][cont->player.posx] = 'P';
	}
	else
		return (0);
	return (1);
}
