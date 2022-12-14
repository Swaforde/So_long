#include "../include/so_long.h"

void	init(t_content *c)
{
	c->exit.x = 0;
	c->exit.y = 0;
	c->player.score = 0;
	c->player.move_count = 0;
	c->image.chad = mlx_xpm_file_to_image(c->mlx, "./ressources/chad.xpm", &c->image.width, &c->image.height);
	c->image.wall = mlx_xpm_file_to_image(c->mlx, "./ressources/wall.xpm", &c->image.width, &c->image.height);
	c->image.erase = mlx_xpm_file_to_image(c->mlx, "./ressources/erase.xpm", &c->image.width, &c->image.height);
	c->image.exit_s = mlx_xpm_file_to_image(c->mlx, "./ressources/exit.xpm", &c->image.width, &c->image.height);
	c->image.coin = mlx_xpm_file_to_image(c->mlx, "./ressources/coin.xpm", &c->image.width, &c->image.height);
}

int	tab_allocation(t_content *cont, char *argv)
{
	t_map		map;
	char		**tab;
	char		**tabtest;

	map.map_path = argv;
	map.height = ft_get_height(map);
	map.width = ft_get_width(map);
	cont->map = map;
	tab = ft_calloc (sizeof(char *), (cont->map.height + 1));
	if (!tab)
		return (0);
	*tab = ft_calloc (sizeof(char), (cont->map.width + 1));
	if (!*tab)
		return (0);
	tabtest = ft_calloc (sizeof(char *), (cont->map.height + 1));
	if (!tabtest)
		return (0);
	*tabtest = ft_calloc (sizeof(char), (cont->map.width + 1));
	if (!*tabtest)
		return (0);
	cont->tab = tab;
	cont->tabTest = tabtest;
	map_parsing(cont->tab, cont->map);
	map_parsing(cont->tabTest, cont->map);
}

int	arguement_check(int argc)
{
	if (argc == 1)
	{
		ft_printf("Error\nVeuillez renseigner un fichier .ber !");
		return (0);
	}
	return (1);
}

void	reset_value(t_content *cont)
{
	cont->exit.x = 0;
	cont->exit.y = 0;
}