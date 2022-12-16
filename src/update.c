/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/12/16 10:30:53 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>

void	put_images(t_content *c, int p_y, int p_x, char tested_char)
{
	if (tested_char == '1')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->i.w, p_y, p_x);
	if (tested_char == 'P')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->i.ch, p_y, p_x);
	if (tested_char == '0')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->i.e, p_y, p_x);
	if (tested_char == 'E')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->i.ex, p_y, p_x);
	if (tested_char == 'C')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->i.c, p_y, p_x);
}

void	update(t_content *content)
{
	int		i;
	int		f;
	int		p_x;
	int		p_y;

	i = 0;
	f = 0;
	p_x = 0;
	p_y = 0;
	while (i < content->map.height)
	{
		while (f < content->map.width)
		{
			put_images(content, p_y, p_x, content->tab[i][f]);
			p_y += 50;
			f ++;
		}
		p_y = 0;
		p_x += 50;
		f = 0;
		i ++;
	}
}
