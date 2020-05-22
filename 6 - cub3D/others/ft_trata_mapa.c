/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trata_mapa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:07:59 by nayran            #+#    #+#             */
/*   Updated: 2020/05/22 16:09:56 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_otherchr(char *s)
{
	int			x;
	static int	teste;

	x = 0;
	if (ft_onlychr(s, "012 NSEW"))
		return (1);
	while (s[x])
	{
		if (s[x] == 'N' || s[x] == 'S' || s[x] == 'E' || s[x] == 'W')
		{
			if (teste == 0)
				teste = 1;
			else
				return (1);
		}
		x++;
	}
	return (0);
}

t_godfather	ft_copiamapa(char *line, t_godfather all)
{
	static int	cont;
	int			x;

	x = ft_strlen(line) - 1;
	all.mapa[cont].line = ft_strdup(line);
	while (line[x] == ' ')
		x--;
	all.mapa[cont].line[x + 1] = '\0';
	all.mapa[cont].width = ft_strlen(all.mapa[cont].line);
	if (ft_otherchr(all.mapa[cont].line) == 1)
	{
		all.caso.error = 10;
		return (all);
	}
	cont++;
	if (all.caso.nread == 0)
		all.mapa = NULL;
	all.caso.map_height = cont;
	return (all);
}

int			ft_mapeamento(t_godfather all)
{
	int cont;
	int y;
	int width;

	cont = 0;
	while (cont < all.caso.map_height)
	{
		width = all.mapa[cont].width - 1;
		if ((cont == 0 || (cont + 1) == all.caso.map_height)
				&& ft_onlychr(all.mapa[cont].line, " 1"))
			return (1);
		y = -1;
		if (all.mapa[cont].line[width] != 49)
			return (1);
		cont++;
	}
	return (ft_mapeamento2(all));
}

t_godfather	ft_tratamapa(char *line, t_godfather all)
{
	all.caso.map = 1;
	if (all.caso.error != 10)
		all = ft_copiamapa(line, all);
	return (all);
}

t_godfather	ft_convertemapa(t_godfather all)
{
	int x;
	int y;

	y = 0;
	all.caso.final_map = (int **)ft_calloc(all.caso.map_height, sizeof(int));
	all.caso.final_map[y] = (int *)ft_calloc(all.caso.map_width, sizeof(int));
	while (y < all.caso.map_height)
	{
		x = 0;
		all.caso.final_map[y] = (int *)malloc(all.caso.map_width * sizeof(int));
		while (x < all.caso.map_width)
		{
			if (all.mapa[y].line[x] == 'N' || all.mapa[y].line[x] == 'S' ||
				all.mapa[y].line[x] == 'E' || all.mapa[y].line[x] == 'W')
				all.caso.final_map[y][x] = all.mapa[y].line[x];
			else
				all.caso.final_map[y][x] = all.mapa[y].line[x] - 48;
			x++;
		}
		y++;
	}
	return (all);
}
