/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/12/19 14:31:11 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_printf ("Error\nFichier invalide !");
	return (fd);
}

void	exit_game(t_content *content, int error)
{
	error_message(error);
	kill_game(content);
}

int	test(int keycode, t_content *content)
{
	int	i;

	i = content->player.move_count;
	if (keycode == 53)
		kill_game(content);
	if (keycode == w || keycode == 126)
		i += forward(content, 0);
	if (keycode == s || keycode == 125)
		i += backward(content, 0);
	if (keycode == d || keycode == 124)
		i += turn_right(content, 0);
	if (keycode == a || keycode == 123)
		i += turn_left(content, 0);
	if (i > content->player.move_count)
	{
		content->player.move_count = i;
		ft_printf("Total move : %d\n", content->player.move_count);
	}
	update(content);
	return (0);
}

void	hooks(t_content *content)
{
	mlx_key_hook(content->mlx_win, &test, content);
	mlx_hook(content->mlx_win, 17, 0, kill_game, content);
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
	if (tab_allocation(&cont, argv[1]) != 1)
		exit_game(&cont, 40);
	cont.player.max_score = get_max_score(cont.tab, cont.map);
	get_start_position(&cont);
	if (map_format_checker(cont.tab, cont.map) != 8)
		exit_game(&cont, map_format_checker(cont.tab, cont.map));
	if (wall_checker(cont.tab, cont.map) != 1)
		exit_game(&cont, 10);
	backtracking(cont.player.posy, cont.player.posx, &cont);
	if (check_all_element(&cont, cont.tab_test) != 0)
		exit_game(&cont, 30);
	cont.mlx = mlx_init();
	cont.mlx_win = mlx_new_window(cont.mlx, cont.ww, cont.wh, "So_Long");
	init(&cont);
	update(&cont);
	hooks(&cont);
}
