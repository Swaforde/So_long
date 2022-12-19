/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/12/19 13:23:30 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include "../GNL/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				y;
	int				x;
	int				a;
	int				b;
	int				c;
	int				d;
	struct s_node	*next;
}		t_node;

typedef struct s_image
{
	int		ph;
	int		pw;
	void	*ch;
	void	*w;
	void	*e;
	void	*c;
	void	*ex;
}		t_image;

typedef struct s_exit
{
	int	y;
	int	x;
}		t_exit;

typedef struct s_player
{
	int	posx;
	int	posy;
	int	move_count;
	int	score;
	int	max_score;
}		t_player;

typedef struct s_map
{
	int		width;
	int		height;
	char	*map_path;
}		t_map;

typedef struct s_content
{
	t_map		map;
	t_image		i;
	t_player	player;
	t_exit		exit;
	int			ww;
	int			wh;
	char		**tab;
	char		**tab_test;
	void		*mlx;
	void		*mlx_win;
}		t_content;

enum e_key
{
	w = 13,
	a = 0,
	s = 1,
	d = 2,
	i = 34
};

int		ft_get_height(t_map map);
int		ft_get_width(t_map map);
void	map_parsing(char **tab, t_map map);
int		wall_checker(char **map, t_map info);
int		map_format_checker(char **map, t_map info);
void	update(t_content *content);
int		forward(t_content *content, int mod);
int		backward(t_content *content, int mod);
int		turn_right(t_content *content, int mod);
int		turn_left(t_content *content, int mod);
void	exit_game(t_content *content);
int		exit_func(t_content *content, int dirY, int dirX);
int		get_max_score(char **tab, t_map map);
void	backtracking(int posY, int posX, t_content *content);
int		check_all_element(t_content *content, char **tab);
void	get_start_position(t_content *content);
int		arguement_check(int argc);
int		tab_allocation(t_content *cont, char *argv);
void	init(t_content *c);
void	reset_value(t_content *cont);
int		error_message(int code);
void	set_window(t_content *content);

#endif