#include "../include/so_long.h"
#include <fcntl.h>

void	forward(t_content *content)
{
	if (content->tab[content->player.posY - 1][content->player.posX] != '1')
	{
		content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posY --;
		content->tab[content->player.posY][content->player.posX] = 'P';
		ft_printf("%d,", content->player.posY);
		ft_printf("%d\n", content->player.posX);
	}
	else
	{
		ft_printf ("Vous ne pouvez pas avancer sur un mur !\n");
	}
}

void	backward(t_content *content)
{
	if (content->tab[content->player.posY + 1][content->player.posX] != '1')
	{
		content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posY ++;
		content->tab[content->player.posY][content->player.posX] = 'P';
		ft_printf("%d,", content->player.posY);
		ft_printf("%d\n", content->player.posX);
	}
	else
	{
		ft_printf ("Vous ne pouvez pas reculer sur un mur !\n");
	}
}

void	turn_right(t_content *content)
{
	if (content->tab[content->player.posY][content->player.posX + 1] != '1')
	{
		content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posX ++;
		content->tab[content->player.posY][content->player.posX] = 'P';
		ft_printf("%d,", content->player.posY);
		ft_printf("%d\n", content->player.posX);
	}
	else
	{
		ft_printf ("Vous ne pouvez pas reculer sur un mur !\n");
	}
}

void	turn_left(t_content *content)
{
	if (content->tab[content->player.posY][content->player.posX - 1] != '1')
	{
		content->tab[content->player.posY][content->player.posX] = '0';
		content->player.posX --;
		content->tab[content->player.posY][content->player.posX] = 'P';
		ft_printf("%d,", content->player.posY);
		ft_printf("%d\n", content->player.posX);
	}
	else
	{
		ft_printf ("Vous ne pouvez pas reculer sur un mur !\n");
	}
}