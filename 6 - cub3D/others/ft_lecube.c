/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:55:58 by nayran            #+#    #+#             */
/*   Updated: 2020/05/22 20:41:16 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_godfather	ft_tratacasos(char *line, t_godfather all)
{
	if ((ft_strstr(line, "R") > 0) && (all.caso.map == 0))
		all = ft_trata_r(line, all);
	else if ((ft_strstr(line, "NO") > 0) && (all.caso.map == 0))
		all = ft_tratageral(line, "NO", all);
	else if ((ft_strstr(line, "SO") > 0) && (all.caso.map == 0))
		all = ft_tratageral(line, "SO", all);
	else if ((ft_strstr(line, "WE") > 0) && (all.caso.map == 0))
		all = ft_tratageral(line, "WE", all);
	else if ((ft_strstr(line, "EA") > 0) && (all.caso.map == 0))
		all = ft_tratageral(line, "EA", all);
	else if ((ft_strstr(line, "S") > 0) && (all.caso.map == 0))
		all = ft_tratageral(line, "S", all);
	else if ((ft_strstr(line, "F") > 0) && (all.caso.map == 0))
		all = ft_tratafc(line, all, 'F');
	else if ((ft_strstr(line, "C") > 0) && (all.caso.map == 0))
		all = ft_tratafc(line, all, 'C');
	else if (ft_strstr(line, "1") > 0)
		all = ft_tratamapa(line, all);
	return (all);
}

t_godfather	inicializa_mapa(void)
{
	t_godfather	m;

	m.caso.map = 0;
	m.caso.error = 0;
	m.caso.final_map = NULL;
	m.mapa = (t_mapa *)malloc(sizeof(t_mapa));
	m.mapa->width = 0;
	m.mapa->line = NULL;
	return (m);
}

t_godfather	ft_lecube(char *path)
{
	int			fd;
	char		*line;
	t_godfather	all;
	int			x;

	x = 0;
	line = NULL;
	all = inicializa_mapa();
	if (!path)
		return (all);
	fd = open(path, O_RDONLY);
	while ((all.caso.nread = get_next_line(fd, &line)) > 0)
		all = ft_tratacasos(line, all);
	if (ft_mapeamento(all) == 1)
		all.caso.error = 10;
	else
		all = ft_mapafinal(all);
	return (all);
}
