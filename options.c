//
// Created by Daria on 22/03/2020.
//

#include "fdf.h"

void reset(t_fdf *fdf)
{
    fdf->win_x = 1440;
    fdf->win_y = 770;
    fdf->zoom = 20;
    fdf->z_scale = 1;
    fdf->iso = 1;
    fdf->angle = 0.523599;
    fdf->x_offset = 0;
    fdf->y_offset = 0;
}

float maximum(float a, float b)
{
    return (a > b ? a : b);
}

float mod(float a)
{
    return (a > 0 ? a : -a);
}

void shift(float *x, float *y, t_fdf *fdf)
{
    *x += fdf->win_x / 3 + fdf->x_offset;
    *y += fdf->win_y / 2 + fdf->y_offset;
}
void get_step(float *x_step, float *y_step)
{
    float max;
    max = maximum(mod(*y_step), mod(*x_step));
    *y_step /= max;
    *x_step /= max;
}