#include "../include/so_long.h"
#include <fcntl.h>

void	forward(t_content *cont)
{
	int	mod;

	mod = 0;
	if (cont->tab[cont->player.posY - 1][cont->player.posX] != '1')
	{
		if (cont->tab[cont->player.posY - 1][cont->player.posX] == 'E')
		{
			if (exit_func(cont, cont->player.posY - 1, cont->player.posX) == 0)
			{
				cont->exit.y = cont->player.posY - 1;
				cont->exit.x = cont->player.posX;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			cont->exit.x = 0;
			cont->exit.y = 0;
		}
		else
			cont->tab[cont->player.posY][cont->player.posX] = '0';
		cont->player.posY --;
		cont->tab[cont->player.posY][cont->player.posX] = 'P';
	}
}

void	backward(t_content *cont)
{
	int	mod;

	mod = 0;
	if (cont->tab[cont->player.posY + 1][cont->player.posX] != '1')
	{
		if (cont->tab[cont->player.posY + 1][cont->player.posX] == 'E')
		{
			if (exit_func(cont, cont->player.posY + 1, cont->player.posX) == 0)
			{
				cont->exit.y = cont->player.posY + 1;
				cont->exit.x = cont->player.posX;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			cont->exit.x = 0;
			cont->exit.y = 0;
		}
		else
			cont->tab[cont->player.posY][cont->player.posX] = '0';
		cont->player.posY ++;
		cont->tab[cont->player.posY][cont->player.posX] = 'P';
	}
}

void	turn_right(t_content *cont)
{
	int	mod;

	mod = 0;
	if (cont->tab[cont->player.posY][cont->player.posX + 1] != '1')
	{
		if (cont->tab[cont->player.posY][cont->player.posX + 1] == 'E')
		{
			if (exit_func(cont, cont->player.posY, cont->player.posX + 1) == 0)
			{
				cont->exit.y = cont->player.posY;
				cont->exit.x = cont->player.posX + 1;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			cont->exit.x = 0;
			cont->exit.y = 0;
		}
		else
			cont->tab[cont->player.posY][cont->player.posX] = '0';
		cont->player.posX ++;
		cont->tab[cont->player.posY][cont->player.posX] = 'P';
	}
}

void	turn_left(t_content *cont)
{
	int	mod;

	mod = 0;
	if (cont->tab[cont->player.posY][cont->player.posX - 1] != '1')
	{
		if (cont->tab[cont->player.posY][cont->player.posX - 1] == 'E')
		{
			if (exit_func(cont, cont->player.posY, cont->player.posX - 1) == 0)
			{
				cont->exit.y = cont->player.posY;
				cont->exit.x = cont->player.posX - 1;
				mod = 1;
			}
		}
		if (cont->exit.y != 0 && cont->exit.x != 0 && mod == 0)
		{
			cont->tab[cont->exit.y][cont->exit.x] = 'E';
			cont->exit.x = 0;
			cont->exit.y = 0;
		}
		else
			cont->tab[cont->player.posY][cont->player.posX] = '0';
		cont->player.posX --;
		cont->tab[cont->player.posY][cont->player.posX] = 'P';
	}
}
