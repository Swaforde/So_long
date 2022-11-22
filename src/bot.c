#include "../include/so_long.h"

// 0 = forward
// 1 = left
// 2 = back
// 3 = left

void	check_block(t_content *c)
{
	int	y;
	int	x;
	int	i;

	y =	c->player.posY;
	x = c->player.posX;
	i = 0;
	if (c->player.latest_dir == 0)
	{
		if (c->tab[y - 1][x] == '1')
			i ++;
		if (c->tab[y][x - 1] == '1')
			i ++;
		if (c->tab[y][x + 1] == '1')
			i ++;
		if (i == 3)
			ft_printf("Cul de sac");
	}
	else if (c->player.latest_dir == 1)
	{
		if (c->tab[y - 1][x] == '1')
			i ++;
		if (c->tab[y][x + 1] == '1')
			i ++;
		if (c->tab[y + 1][x] == '1')
			i ++;
		if (i == 3)
			ft_printf("Cul de sac");
	}
	else if (c->player.latest_dir == 2)
	{
		if (c->tab[y + 1][x] == '1')
			i ++;
		if (c->tab[y][x + 1] == '1')
			i ++;
		if (c->tab[y][x - 1] == '1')
			i ++;
		if (i == 3)
			ft_printf("Cul de sac");
	}
	if (c->player.latest_dir == 3)
	{
		if (c->tab[y - 1][x] == '1')
			i ++;
		if (c->tab[y][x - 1] == '1')
			i ++;
		if (c->tab[y + 1][x] == '1')
			i ++;
		if (i == 3)
			ft_printf("Cul de sac");
	}
}

void	check_node(t_content *c)
{
	int	y;
	int	x;
	int	i;

	y =	c->player.posY;
	x = c->player.posX;
	i = 0;
	if (c->player.latest_dir == 0)
	{
		if (c->tab[y - 1][x] != '1')
			i ++;
		if (c->tab[y][x - 1] != '1')
			i ++;
		if (c->tab[y][x + 1] != '1')
			i ++;
		if (i < 2)
			return ;
	}
	else if (c->player.latest_dir == 1)
	{
		if (c->tab[y - 1][x] != '1')
			i ++;
		if (c->tab[y][x + 1] != '1')
			i ++;
		if (c->tab[y + 1][x] != '1')
			i ++;
		if (i < 2)
			return ;
	}
	else if (c->player.latest_dir == 2)
	{
		if (c->tab[y + 1][x] != '1')
			i ++;
		if (c->tab[y][x + 1] != '1')
			i ++;
		if (c->tab[y][x - 1] != '1')
			i ++;
		if (i < 2)
			return ;
	}
	if (c->player.latest_dir == 3)
	{
		if (c->tab[y - 1][x] != '1')
			i ++;
		if (c->tab[y][x - 1] != '1')
			i ++;
		if (c->tab[y + 1][x] != '1')
			i ++;
		if (i < 2)
			return ;
	}
	ft_printf("Embranchement : %d ", i);
	ft_printf(", type (%d)", c->player.latest_dir);
	ft_printf ("[%d x ", y);
	ft_printf ("%d]\n", x);
}

int	bot_choice(t_content *c)
{
	int	y;
	int	x;

	y =	c->player.posY;
	x = c->player.posX;
	if (c->tab[y - 1][x] != '1' && c->player.latest_dir != 2)
		return 0;
	if (c->tab[y][x + 1] != '1' && c->player.latest_dir != 3)
		return 1;
	if (c->tab[y + 1][x] != '1' && c->player.latest_dir != 0)
		return 2;
	if (c->tab[y][x - 1] != '1' && c->player.latest_dir != 1)
		return 3;
}

void	launch_bot(t_content *content)
{
	int	i;
	int	x;
	int	s;
	int	b;

	s = 0;
	i = 5;
	x = 0;
	b = 0;
	ft_printf("------------------------\n|Auto player launched !|\n------------------------\n");
	while (x <= 0)
	{
		s = bot_choice(content);
		b = 1;
		if (s == 0)
		{
			ft_printf("Forward\n");
				content->player.latest_dir = 0;
				b = forward(content);
				check_node(content);
				check_block(content);
		}
		if (s == 1)
		{
			ft_printf("Right\n");
				content->player.latest_dir = 1;
				b = turn_right(content);
				check_node(content);
				check_block(content);
		}
		if (s == 2)
		{
			ft_printf("Backward\n");
				content->player.latest_dir = 2;
				b = backward(content);
				check_node(content);
				check_block(content);
		}
		if (s == 3)
		{
			ft_printf("Left\n");
				content->player.latest_dir = 3;
				b = turn_left(content);
				check_node(content);
				check_block(content);
		}
		if (s == 10)
			return ;
		update(content);
		ft_printf ("---------New---------\n");
		x ++;
		s = 0;
	}
	ft_printf("----------------------\n|Auto player stoped !|\n----------------------\n");
}