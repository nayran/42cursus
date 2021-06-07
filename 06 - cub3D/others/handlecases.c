/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlecases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:44:08 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 05:22:14 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_resolution(t_godfather *all, const char **line)
{
	all->wx = ft_atoi(*line);
	if (all->wx < 100)
		all->wy = 100;
	if (all->wx > 1280)
		all->wx = 1280;
	if (all->wx % 4)
		all->wx = all->wx - all->wx % 4;
	ft_skip(line, "0123456789");
	ft_skip(line, " ");
	all->wy = ft_atoi(*line);
	if (all->wy < 100)
		all->wy = 100;
	if (all->wy > 800)
		all->wy = 800;
	if (all->wy % 4)
		all->wy = all->wy - all->wy % 4;
	ft_skip(line, "0123456789");
	return (10);
}

static char	*ft_path(char **line)
{
	char	*path;
	int		fd;

	path = *line;
	while (**line && **line != '\n')
		(*line)++;
	if (!**line)
		return (NULL);
	else
		**line = '\0';
	(*line)++;
	fd = open(path, O_RDONLY);
	if (read(fd, path, 0) < 0)
		path = NULL;
	close(fd);
	return (path);
}

static void	ft_loadtex(t_godfather *all, char *path, size_t index, int size)
{
	all->text[index].img = mlx_xpm_file_to_image(all->mlx, path, &size, &size);
	all->text[index].data = (int*)mlx_get_data_addr(all->text[index].img,
	&all->text[index].bpp, &all->text[index].size_l, &all->text[index].endian);
	all->text[index].bpp /= 8;
}

int			ft_textures(t_godfather *all, const char **line, int i)
{
	char		*path;

	if ((path = ft_path((char**)line)) == NULL)
		return (6);
	if (i == 0)
		ft_loadtex(all, path, 0, 64);
	else if (i == 1)
		ft_loadtex(all, path, 1, 64);
	else if (i == 2)
		ft_loadtex(all, path, 2, 64);
	else if (i == 3)
		ft_loadtex(all, path, 3, 64);
	else if (i == 4)
		ft_loadtex(all, path, 4, 64);
	return (10);
}

int			ft_color(t_godfather *all, const char **line, int i)
{
	t_rgb	color;

	color.r = ft_atoi(*line);
	if (color.r < 0x0 || color.r > 0xFF)
		return (7);
	ft_skip(line, "0123456789");
	ft_skip(line, " ,");
	color.g = ft_atoi(*line);
	if (color.g < 0x0 || color.g > 0xFF)
		return (7);
	ft_skip(line, "0123456789");
	ft_skip(line, " ,");
	color.b = ft_atoi(*line);
	if (color.b < 0x0 || color.b > 0xFF)
		return (7);
	ft_skip(line, "0123456789");
	if (i == 6)
		all->color[0] = color.r << 16 | color.g << 8 | color.b;
	if (i == 7)
		all->color[1] = color.r << 16 | color.g << 8 | color.b;
	return (10);
}
