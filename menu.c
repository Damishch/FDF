/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorilee <alorilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 22:08:24 by alorilee          #+#    #+#             */
/*   Updated: 2020/05/06 22:08:32 by alorilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_menu(t_fdf *fdf)
{
    char *title;
    title = "press ESC to exit";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 10, 0x03fc35, title);
    title = "press R to reset";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 50, 0x03fc35, title);
    title = "press +/- to zoom";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 70, 0x03fc35, title);
    title = "press I to change POV";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 90, 0x03fc35, title);
    title = "use WASD to move image";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 110, 0x03fc35, title);
    title = "press arrow up/down to scale Z";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 130, 0x03fc35, title);
    title = "press Q/E to rotate image";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 150, 0x03fc35, title);
}