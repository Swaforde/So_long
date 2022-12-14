#include "../include/so_long.h"

int	check_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_printf ("Error\nFichier invalide !");
	return (fd);
}

void	exit_game(t_content *content, char *msg)
{
	int	i;

	i = 0;
	if (msg != NULL)
		ft_printf("%s", msg);
	mlx_destroy_image(content->mlx, content->mlx_win);
	while (i <= content->map.height)
	{
		free (content->tab[i]);
		i ++;
	}
	while (i <= content->map.height)
	{
		free (content->tabTest[i]);
		i ++;
	}
	exit(0);
}

int	test(int keycode, t_content *content)
{
	if (keycode == 53)
	{
		exit_game(content, NULL);
	}
	if (keycode == w || keycode == 126)
	{
		forward(content);
		update(content);
	}
	if (keycode == s || keycode == 125)
	{
		backward(content);
		update(content);
	}
	if (keycode == d || keycode == 124)
	{
		turn_right(content);
		update(content);
	}
	if (keycode == a || keycode == 123)
	{
		turn_left(content);
		update(content);
	}		
	return (0);
}

void	hooks(t_content *content)
{
	mlx_key_hook(content->mlx_win, &test, content);
	mlx_loop(content->mlx);
}

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

int	main(int argc, char *argv[])
{
	t_map		map;
	t_content	cont;
	void		*mlx_win;
	void		*test;

	if (arguement_check(argc) == 0)
		return (0);
	if (check_file(argv[1]) < 0)
		return (0);
	tab_allocation(&cont, argv[1]);
	cont.player.max_score = get_max_score(cont.tab, cont.map);
	get_start_position(&cont);
	if (map_format_checker(cont.tab, cont.map) != 1)
		return (0);
	if (wall_checker(cont.tab, cont.map) != 1)
		return (0);
	backtracking(cont.player.posY, cont.player.posX, &cont);
	if (check_all_element(&cont, cont.tabTest) != 0)
		return (0);
	cont.mlx = mlx_init();
	cont.mlx_win = mlx_new_window(cont.mlx, cont.map.width * 50, cont.map.height * 50, "So_Long");
	init(&cont);
	update(&cont);
	hooks(&cont);
}
