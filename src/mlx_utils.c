#include "../include/so_long.h"

void    ft_draw_rec(t_data data, int posX, int posY, int w, int h, int color)
{
    int maxW;
    int maxH;

    maxW = 0;
    maxH = 0;

    while (maxH != h)
    {
        while (maxW != w)
        {
            my_mlx_pixel_put(&data, maxH, maxW, color);
            maxW ++;
        }
        maxW = 0;
        maxH ++;
    }
}   