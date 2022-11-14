#include "../include/so_long.h"

int	check_file(char *map)
{
	return (open(map, O_RDONLY));
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	char	**tab;
	int		i;

	i = 0;
	t_map	map;
	t_data	img;

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
	tab = ft_calloc (sizeof(char *), (map.height + 1));
	*tab = ft_calloc (sizeof(char), (map.width + 1));
	map_parsing(tab, map);
	if (map_format_checker(tab, map) != 1)
		return (0);	
	if (wall_checker(tab, map) != 1)
		return (0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.width * 100, map.height * 100, "Hello world!");
	display_wall(tab, mlx, mlx_win, map);
	mlx_loop(mlx);
}