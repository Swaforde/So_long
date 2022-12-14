#include "../include/so_long.h"

int	exit_func(t_content *content, int dirY, int dirX)
{
	if (content->player.score == content->player.max_score)
	{
		exit_game(content, "vous avez terminé le jeu !");
	}
	else
	{
		ft_printf("\n(Attendu : %d", content->player.max_score);
		ft_printf(" Vous : %d)\n", content->player.score);
		ft_printf("Vous n'avez pas ramsser tous les objets !");
		return (0);
	}
	return (1);
}
