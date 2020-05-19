/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorilee <alorilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 01:29:18 by alorilee          #+#    #+#             */
/*   Updated: 2020/05/20 01:31:30 by alorilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_x_value(char *file)
{
	char	*line;
	int		fd;
	int		x;

	if (!((fd = open(file, O_RDONLY)) >= 0))
		terminate(ERR_MAP);
	if (get_next_line(fd, &line) == -1)
		terminate(ERR_MAP);
	x = ft_countwords(line, ' ');
	free(line);
	close(fd);
	return (x);
}

int		get_y_value(char *file, t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		y;
	int		result;

	fd = open(file, O_RDONLY);
	y = 0;
	while ((result = get_next_line(fd, &line)) == 1)
	{
		y++;
		free(line);
	}
	if (result < 0)
		terminate(ERR_MAP);
	if (fdf->x == 0 && y == 0)
		terminate(ERR_MAP_READING);
	free(line);
	close(fd);
	return (y);
}

void	fill_z(int *z_values, char *line)
{
	char	**values;
	int		i;
	int		flag;

	values = ft_strsplit(line, ' ');
	i = 0;
	flag = 1;
	while (values[i])
	{
		if (!(ft_isnumber(values[i])))
			flag = 0;
		if (ft_atoi(values[i]) > 100046)
			terminate(ERR_MAP_VALUE);
		z_values[i] = ft_atoi(values[i]);
		free(values[i]);
		i++;
	}
	free(values);
	if (flag == 0)
		terminate(ERR_MAP_READING);
}

void	read_file(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;

	fdf->x = get_x_value(file);
	fdf->y = get_y_value(file, fdf);
	fdf->z_values = (int**)malloc(sizeof(int *) * (fdf->y + 1));
	i = 0;
	while (i < fdf->y)
		fdf->z_values[i++] = (int*)malloc(sizeof(int) * (fdf->x + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_z(fdf->z_values[i++], line);
		free(line);
	}
	free(line);
	close(fd);
	fdf->z_values[i] = NULL;
}

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}
