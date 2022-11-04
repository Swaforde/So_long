#include "../include/so_long.h"

int	main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 300, "So_Long");
	mlx_loop(mlx);
	return (1);
}
