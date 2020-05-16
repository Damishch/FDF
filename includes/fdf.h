/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorilee <alorilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:38:21 by alorilee          #+#    #+#             */
/*   Updated: 2020/05/16 22:07:24 by alorilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <errno.h>

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_MAP_READING	"Reading error"
# define ERR_MAP_VALUE		"Reading error - wrong Z value"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CONV_TO_ARR	"Conversion to array"
# define ERR_CAMERA_INIT	"Camera initialization error"

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	float		win_x;
	float		win_y;
	int			x;
	int			y;
	int			**z_values;
	int			zoom;
	int			z_scale;
	int			color;
	int			iso;
	double		angle;
	float		x_offset;
	float		y_offset;
}				t_fdf;

void			read_file(char *file, t_fdf *fdf);
void			draw_line(float x, float y, float x1, float y1, t_fdf *fdf);
void			draw_map(t_fdf *fdf);
void			print_menu(t_fdf *fdf);
void			reset(t_fdf *fdf);
float			maximum(float a, float b);
float			mod(float a);
void			shift(float *x, float *y, t_fdf *fdf);
void			get_step(float *x_step, float *y_step);
void			terminate(char *s);
#endif
