/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorilee <alorilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 01:33:44 by alorilee          #+#    #+#             */
/*   Updated: 2020/05/14 21:07:30 by alorilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *fdf)
{
	*x = (*x - *y) * cos(fdf->angle);
	*y = (*x + *y) * sin(fdf->angle) - z;
}

void	zoom(float *x, float *y, int *z, t_fdf *fdf)
{
	*z = fdf->z_values[(int)*y][(int)*x];
	*x *= (float)(fdf->zoom);
	*y *= (float)(fdf->zoom);
	*z *= fdf->z_scale;
}

void	draw_line_x(float x, float y, float x1, t_fdf *fdf)
{
	float	y_step;
	float	x_step;
	int		z;
	int		z1;
	float	y1;

	y1 = y;
	zoom(&x, &y, &z, fdf);
	zoom(&x1, &y1, &z1, fdf);
	fdf->color = (z || z1) ? 0xe80c0c : 0xffffff;
	if (fdf->iso > 0)
		isometric(&x, &y, z, fdf);
	if (fdf->iso > 0)
		isometric(&x1, &y1, z1, fdf);
	shift(&x, &y, fdf);
	shift(&x1, &y1, fdf);
	y_step = y1 - y;
	x_step = x1 - x;
	get_step(&x_step, &y_step);
	while ((int)(x1 - x) || (int)(y1 - y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)x, (int)y, fdf->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_line_y(float x, float y, float y1, t_fdf *fdf)
{
	float	y_step;
	float	x_step;
	int		z;
	int		z1;
	float	x1;

	x1 = x;
	zoom(&x, &y, &z, fdf);
	zoom(&x1, &y1, &z1, fdf);
	fdf->color = (z || z1) ? 0xe80c0c : 0xffffff;
	if (fdf->iso > 0)
		isometric(&x, &y, z, fdf);
	if (fdf->iso > 0)
		isometric(&x1, &y1, z1, fdf);
	shift(&x, &y, fdf);
	shift(&x1, &y1, fdf);
	y_step = y1 - y;
	x_step = x1 - x;
	get_step(&x_step, &y_step);
	while ((int)(x1 - x) || (int)(y1 - y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)x, (int)y, fdf->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_map(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->y)
	{
		x = 0;
		while (x < fdf->x)
		{
			if (x < fdf->x - 1)
				draw_line_x((float)x, (float)y, (float)(x + 1), fdf);
			if (y < fdf->y - 1)
				draw_line_y((float)x, (float)y, (float)(y + 1), fdf);
			x++;
		}
		y++;
	}
}
