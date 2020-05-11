/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorilee <alorilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 01:17:10 by alorilee          #+#    #+#             */
/*   Updated: 2020/05/11 18:01:42 by alorilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_key(int key)
{
	return (key == 24 || key == 27 || key == 15 || key == 126 || key == 125 ||
			key == 34 || key == 12 || key == 13 || key == 0 || key == 1
			|| key == 2 || key == 53 || key == 14);
}

void	do_this(int key, t_fdf *fdf)
{
	if (key == 15)
		reset(fdf);
	if (key == 12)
		fdf->angle -= 0.05;
	if (key == 14)
		fdf->angle += 0.05;
	if (key == 13)
		if (fdf->y + fdf->win_y / 2 + fdf->y_offset > 46)
			fdf->y_offset -= 50;
	if (key == 0)
		if (fdf->x + fdf->win_x / 3 + fdf->x_offset > 249)
			fdf->x_offset -= 50;
	if (key == 1)
		if (fdf->y + fdf->win_y / 2 + fdf->y_offset < 596)
			fdf->y_offset += 50;
	if (key == 2)
		if (fdf->x + fdf->win_x / 3 + fdf->x_offset < 1099)
			fdf->x_offset += 50;
}

void	do_that(int key, t_fdf *fdf)
{
	if (key == 24)
		fdf->zoom += 5;
	if (key == 27)
		if (fdf->zoom - 5 >= 0)
			fdf->zoom -= 5;
	if (key == 126)
		fdf->z_scale++;
	if (key == 125)
		fdf->z_scale--;
	if (key == 34)
		fdf->iso = fdf->iso > 0 ? -1 : 1;
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free(fdf);
		exit(0);
	}
}

int		deal_key(int key, t_fdf *fdf)
{
	if (is_key(key))
	{
		if (key <= 15)
			do_this(key, fdf);
		else
			do_that(key, fdf);
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		print_menu(fdf);
		draw_map(fdf);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf *fdf;

	if (ac != 2)
		write(1, "usage: ./fdf @map@\n", 19);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	read_file(av[1], fdf);
	reset(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, (int)fdf->win_x,
	(int)fdf->win_y, "FDF");
	print_menu(fdf);
	draw_map(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
