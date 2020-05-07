//
// Created by Daria on 19/03/2020.
//

#ifndef FDF_FDF_H
#define FDF_FDF_H

#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include <math.h>

//gcc main.c fdf.h ./libft/libft.a ./minilibx_macos/libmlx.a  -framework OpenGL -framework AppKit

typedef struct
{
    void *mlx_ptr;
    void *win_ptr;
    float win_x;
    float win_y;
    int x;
    int y;
    int **z_values;
    int zoom;
    int z_scale;
    int color;
    int iso;
    double angle;
    float x_offset;
    float y_offset;
}               t_fdf;

void    read_file(char *file, t_fdf *fdf);
void draw_line(float x, float y, float x1, float y1, t_fdf *fdf);
void draw_map(t_fdf *fdf);
void print_menu(t_fdf *fdf);
void reset(t_fdf *fdf);
float maximum(float a, float b);
float mod(float a);
void shift(float *x, float *y, t_fdf *fdf);
void get_step(float *x_step, float *y_step);
#endif //FDF_FDF_H
