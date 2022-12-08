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
	int	y;
	int	x;
	int	a;
	int b;
	int	c;
	int	d;
	struct s_node	*next;
}		t_node;


typedef struct	s_image
{
	int	height;
	int	width;
	void *chad;
	void *wall;
	void *erase;
	void	*coin;
	void	*exit_s;
}		t_image;

typedef	struct s_exit
{
	int	y;
	int	x;
}		t_exit;


typedef struct s_player
{
	int	posX;
	int	posY;
	int	move_count;
	int	score;
	int	max_score;
	int	latest_dir;
}		t_player;


typedef struct s_map
{
	int		width;
	int		height;
	char	*map_path;
}		t_map;

typedef struct s_content
{
	t_map	map;
	t_image	image;
	t_player player;
	t_exit exit;
	char	**tab;
	void	*mlx;
	void	*mlx_win;
}		t_content;

enum	key
{
	w = 13,
	a = 0,
	s = 1,
	d = 2,
	i = 34
};

int		ft_get_height(t_map);
int		ft_get_width(t_map map);
void	map_parsing(char **tab, t_map map);
void	display_wall(char **map, void *mlx, void *mlx_win, t_content *content);
int		wall_checker(char **map, t_map info);
int		map_format_checker(char **map, t_map info);
void	update(t_content *content);
int	forward(t_content *content);
int	backward(t_content *content);
int	turn_right(t_content *content);
int	turn_left(t_content *content);
void	exit_game(t_content *content, char *msg);
int		exit_func(t_content *content, int dirY, int dirX);
int		get_max_score (char **tab, t_map map);

t_node    *last_node(t_node *node);
void    delete_node(t_node *node);
void    add_node_back(t_node  *new, t_node  *node);
void    add_node_front(t_node *new, t_node **node);
t_node    *new_node(int   x, int  y);

#endif