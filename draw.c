//
// Created by Daria on 19/03/2020.
//

#include "fdf.h"

void isometric(float *x, float *y, int z, t_fdf *fdf)
{
    *x = (*x - *y) * cos(fdf->angle);
    *y = (*x + *y) * sin(fdf->angle) - z;
}

void zoom(float *x, float *y, int *z, t_fdf  *fdf)
{
    *z = fdf->z_values[(int)*y][(int)*x];
    *x *= (float)(fdf->zoom);
    *y *= (float)(fdf->zoom);
    *z *= fdf->z_scale;
}

void draw_line(float x, float y, float x1, float y1, t_fdf *fdf)
{
    float y_step;
    float x_step;
    int z;
    int z1;

    zoom(&x, &y, &z, fdf);
    zoom(&x1, &y1, &z1, fdf);
    fdf->color = (z || z1) ? 0xe80c0c : 0xffffff;
    if (fdf->iso > 0)
    {
        isometric(&x, &y, z, fdf);
        isometric(&x1, &y1, z1, fdf);
    }
    shift(&x, &y, fdf);
    shift(&x1, &y1, fdf);
    y_step = y1 - y;
    x_step = x1 - x;
    get_step(&x_step, &y_step);
    while((int)(x1 - x) || (int)(y1 - y))
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)x, (int)y, fdf->color);
        x += x_step;
        y += y_step;
    }
}

void draw_map(t_fdf *fdf)
{
    int x;
    int y;

    y = 0;
    while(y < fdf->y)
    {
        x = 0;
        while(x < fdf->x)
        {
            if(x < fdf->x - 1)
                draw_line((float)x, (float)y, (float)(x + 1), (float)y, fdf);
            if(y < fdf->y - 1)
                draw_line((float)x, (float)y, (float)x, (float)(y + 1), fdf);
            x++;
        }
        y++;
    }
}