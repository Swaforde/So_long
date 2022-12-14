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
		exit_game(content, NULL);
	if (keycode == w || keycode == 126)
		content->player.move_count += forward(content, 0);
	if (keycode == s || keycode == 125)
		content->player.move_count += backward(content, 0);
	if (keycode == d || keycode == 124)
		content->player.move_count += turn_right(content, 0);
	if (keycode == a || keycode == 123)
		content->player.move_count += turn_left(content, 0);
	ft_printf("Total move : %d\n", content->player.move_count);
	update(content);
	return (0);
}

void	hooks(t_content *content)
{
	mlx_key_hook(content->mlx_win, &test, content);
	mlx_loop(content->mlx);
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
