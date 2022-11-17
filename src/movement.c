#include "../include/so_long.h"
#include <fcntl.h>

void	forward(t_content *content)
{
	int	mod;

	mod = 0;
	if (content->tab[content->player.posY - 1][content->player.posX] != '1')
	{
		if (content->tab[content->player.posY - 1][content->player.posX] == 'E')
		{
			if (exit_func(content, content->player.posY - 1, content->player.posX) == 0)
			{
				content->exit.y = content->player.posY - 1;
				content->exit.x = content->player.posX;
				mod = 1;
			}
		}
		if (content->exit.y != 0 && content->exit.x != 0 && mod == 0)
		{
			content->tab[content->exit.y][content->exit.x] = 'E';
			content->exit.x = 0;
			content->exit.y = 0;
		}
		else
			content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posY --;
		content->tab[content->player.posY][content->player.posX] = 'P';
	}
}

void	backward(t_content *content)
{
	int	mod;

	mod = 0;
	if (content->tab[content->player.posY + 1][content->player.posX] != '1')
	{
		if (content->tab[content->player.posY + 1][content->player.posX] == 'E')
		{
			if (exit_func(content, content->player.posY + 1, content->player.posX) == 0)
			{
				content->exit.y = content->player.posY + 1;
				content->exit.x = content->player.posX;
				mod = 1;
			}
		}
		if (content->exit.y != 0 && content->exit.x != 0 && mod == 0)
		{
			content->tab[content->exit.y][content->exit.x] = 'E';
			content->exit.x = 0;
			content->exit.y = 0;
		}
		else
			content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posY ++;
		content->tab[content->player.posY][content->player.posX] = 'P';
	}
}

void	turn_right(t_content *content)
{
	int	mod;

	mod = 0;
	if (content->tab[content->player.posY][content->player.posX + 1] != '1')
	{
		if (content->tab[content->player.posY][content->player.posX + 1] == 'E')
		{
			if (exit_func(content, content->player.posY, content->player.posX + 1) == 0)
			{
				content->exit.y = content->player.posY;
				content->exit.x = content->player.posX + 1;
				mod = 1;
			}
		}
		if (content->exit.y != 0 && content->exit.x != 0 && mod == 0)
		{
			content->tab[content->exit.y][content->exit.x] = 'E';
			content->exit.x = 0;
			content->exit.y = 0;
		}
		else
			content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posX ++;
		content->tab[content->player.posY][content->player.posX] = 'P';
	}
}

void	turn_left(t_content *content)
{
	int	mod;

	mod = 0;
	if (content->tab[content->player.posY][content->player.posX - 1] != '1')
	{
		if (content->tab[content->player.posY][content->player.posX - 1] == 'E')
		{
			if (exit_func(content, content->player.posY, content->player.posX - 1) == 0)
			{
				content->exit.y = content->player.posY;
				content->exit.x = content->player.posX - 1;
				mod = 1;
			}
		}
		if (content->exit.y != 0 && content->exit.x != 0 && mod == 0)
		{
			content->tab[content->exit.y][content->exit.x] = 'E';
			content->exit.x = 0;
			content->exit.y = 0;
		}
		else
			content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posX --;
		content->tab[content->player.posY][content->player.posX] = 'P';
	}
}
