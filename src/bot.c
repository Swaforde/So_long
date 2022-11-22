#include "../include/so_long.h"

// 0 = forward
// 1 = left
// 2 = back
// 3 = left

int	bot_choice(t_content *content)
{
	int	choice;

	choice = 0;
	
	return (choice);
}

void	launch_bot(t_content *content)
{
	ft_printf("------------------------\n|Auto player launched !|\n------------------------\n");
	sleep (2);
	if (bot_choice == 0)
		forward (content);
	else if (bot_choice == 1)
		turn_right(content);
	else if (bot_choice == 2)
		backward (content);
	else if (bot_choice == 3)
		turn_left(content);
	ft_printf("%d x", content->player.posY);
	ft_printf("%d x\n", content->player.posX);
	update(content);
	ft_printf("----------------------\n|Auto player stoped !|\n----------------------\n");
}