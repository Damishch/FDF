//
// Created by Daria on 19/03/2020.
//

#include "fdf.h"

int get_x_value(char *file)
{
    char *line;
    int fd;
    int x;

    fd = open(file, O_RDONLY);
    get_next_line(fd, &line);
    x = ft_countwords(line, ' ');
    free(line);
    close(fd);
    return(x);
}

int get_y_value(char *file)
{
    char *line;
    int fd;
    int y;

    fd = open(file, O_RDONLY);
    y = 0;
    while(get_next_line(fd, &line))
    {
        y++;
        free(line);
    }
    free(line);
    close(fd);
    return (y);
}

void fill_z(int *z_values, char *line)
{
    char **values;
    int i;

    values = ft_strsplit(line, ' ');
    i = 0;
    while (values[i])
    {
        z_values[i] = ft_atoi(values[i]);
        free(values[i]);
        i++;
    }
    free(values);
}

void    read_file(char *file, t_fdf *fdf)
{
    int fd;
    char *line;
    int i;

    fdf->x = get_x_value(file);
    fdf->y = get_y_value(file);
    fdf->z_values = (int**)malloc(sizeof(int *) * (fdf->y + 1));
    i = 0;
    while (i < fdf->y)
        fdf->z_values[i++] = (int*)malloc(sizeof(int) * (fdf->x + 1));
    fd = open(file, O_RDONLY);
    i = 0;
    while(get_next_line(fd, &line))
    {
        fill_z(fdf->z_values[i], line);
        free(line);
        i++;
    }
    free(line); // new one
    close(fd);
    fdf->z_values[i] = NULL;
}