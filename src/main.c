#include "../include/so_long.h"

int	check_file(char *map)
{
	return (open(map, O_RDONLY));
}

int	test(int keycode, t_content *content)
{
	if (keycode == 53) {
		mlx_destroy_image(content->mlx, content->mlx_win);
		exit(0);
	}
	if (keycode == w)
	{
		forward(content);
		update(content);
	}
	if (keycode == s)
	{
		backward(content);
		update(content);
	}
	if (keycode == d)
	{
		turn_right(content);
		update(content);
	}
	if (keycode == a)
	{
		turn_left(content);
		update(content);
	}
	return (0);
}

void hooks(t_content *content) {
	mlx_key_hook(content->mlx_win, &test, content);
	mlx_loop(content->mlx);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_content cont;
	void	*mlx_win;
	char	**tab;
	int		i;
	void	*test;
	i = 0;

	if (argc == 1)
	{
		ft_printf("Veuillez renseigner une map.ber !");
		return (0);
	}
	if (check_file(argv[1]) < 0)
	{
		ft_printf ("Fichier invalide !");
		return (0);
	}
	map.map_path = argv[1];
	map.height = ft_get_height(map);
	map.width = ft_get_width(map);
	cont.map = map;
	tab = ft_calloc (sizeof(char *), (cont.map.height + 1));
	*tab = ft_calloc (sizeof(char), (cont.map.width + 1));
	cont.tab = tab;
	map_parsing(cont.tab, cont.map);
	if (map_format_checker(cont.tab, cont.map) != 1)
		return (0);
	if (wall_checker(cont.tab, cont.map) != 1)
		return (0);
	cont.mlx = mlx_init();
	cont.mlx_win = mlx_new_window(cont.mlx, cont.map.width * 100, cont.map.height * 100, "Hello world!");
	cont.image.chad = mlx_xpm_file_to_image(cont.mlx, "./ressources/chad.xpm", &cont.image.width, &cont.image.height);
	cont.image.wall = mlx_xpm_file_to_image(cont.mlx, "./ressources/wall.xpm", &cont.image.width, &cont.image.height);
	cont.image.erase = mlx_xpm_file_to_image(cont.mlx, "./ressources/erase.xpm", &cont.image.width, &cont.image.height);
	display_wall(cont.tab, cont.mlx, cont.mlx_win, &cont);
	hooks(&cont);
}