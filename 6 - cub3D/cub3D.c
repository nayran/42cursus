/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <nayran@nayran.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 18:44:12 by nasimon-          #+#    #+#             */
/*   Updated: 2020/06/01 08:50:05 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_error(int error)
{
	if (error == 10)
		printf("Error\nMAP ERROR\n");
	if (error == 11)
		printf("Error\nSCREEN SIZE ERROR\n");
}

t_godfather	ft_inicializa_mapa(char *path)
{
	t_godfather	all;
	int			fd;
	char		*line;
	ssize_t		nread;

	line = NULL;
	all.error = 0;
	all.bmp = 0;
	all.mapaa = NULL;
	all.map.map = NULL;
	all.map.map_width = 0;
	fd = open(path, O_RDONLY);
	while ((nread = get_next_line(fd, &line)) > 0)
		all = ft_tratacasos(line, all);
	close(fd);
	if (ft_mapeamento(all) == 1)
		all.error = 10;
	else
		return (ft_mapafinal(all));
	return (all);
}

int			main(int argc, char **argv)
{
	t_godfather	all;

	if (argv[1] && argc != 0)
		all = ft_inicializa_mapa(argv[1]);
	else
		all.error = 10;
	if (argv[2])
		if (ft_exactstr(argv[2], "--save"))
			all.bmp = 1;
	ft_window(all);
	return (0);
}
