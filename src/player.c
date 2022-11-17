#include "../include/so_long.h"

int	exit_func(t_content *content, int dirY, int dirX)
{
	int	score;

	score = 4;
	ft_printf("(%d,", dirY);
	ft_printf("%d)\n", dirX);
	if (score == 5)
	{
		exit_game(content, "vous avez terminé le jeu !");
	}
	else 
	{
		ft_printf("Vous n'avez pas ramsser tous les objets !");
		return (0);
	}
	return (1);
}