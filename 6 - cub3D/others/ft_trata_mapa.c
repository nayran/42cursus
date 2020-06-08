/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trata_mapa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:07:59 by nayran            #+#    #+#             */
/*   Updated: 2020/06/03 23:19:43 by nayran           ###   ########.fr       */
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
	char		**aux;

	aux = (char **)malloc(sizeof(char **) * (cont + 1));
	aux[0] = NULL;
	x = cont;
	while (--x >= 0)
		aux[x] = ft_strdup(all.mapaa[x]);
	free(all.mapaa);
	all.mapaa = (char **)malloc(sizeof(char **) * (cont + 1));
	while (++x < cont)
		all.mapaa[x] = ft_strdup(aux[x]);
	all.mapaa[cont] = ft_strdup(line);
	x = ft_strlen(line) - 1;
	while (line[x] == ' ')
		all.mapaa[cont][x--] = '\0';
	x = (int)ft_strlen(all.mapaa[cont]) - 1;
	if (all.map.map_width < x)
		all.map.map_width = x + 1;
	if (ft_otherchr(all.mapaa[cont++]) == 1)
		all.error = 10;
	all.map.map_height = cont;
	free(aux);
	return (all);
}

t_godfather	ft_convertemapa(t_godfather all)
{
	int x;
	int y;

	y = 0;
	all.map.map = (int **)ft_calloc(all.map.map_height, sizeof(int *));
	while (y < all.map.map_height)
	{
		x = 0;
		all.map.map[y] = (int *)malloc(all.map.map_width * sizeof(int));
		while (x < all.map.map_width)
		{
			if (all.mapaa[y][x] == 'N' || all.mapaa[y][x] == 'S' ||
				all.mapaa[y][x] == 'E' || all.mapaa[y][x] == 'W')
			{
				all.map.map[y][x] = 0;
				all.player.x = x;
				all.player.y = y;
			}
			else
				all.map.map[y][x] = all.mapaa[y][x] - 48;
			x++;
		}
		y++;
	}
	return (all);
}

char		*ft_enquadro(char *str, int width)
{
	char	*aux;
	int		x;

	x = 0;
	aux = (char *)malloc(width + 1);
	while (str[x])
	{
		if (str[x] == ' ')
			aux[x] = '1';
		else
			aux[x] = str[x];
		x++;
	}
	width = width - ft_strlen(str);
	while (width > 0)
	{
		aux[x] = '1';
		width--;
		x++;
	}
	aux[x] = '\0';
	return (aux);
}

t_godfather	ft_mapafinal(t_godfather all)
{
	int cont;
	int x;
	int width;

	width = 0;
	cont = 0;
	while (cont < all.map.map_height)
	{
		if (width < all.map.map_width)
			width = all.map.map_width;
		cont++;
	}
	cont = 0;
	while (cont < all.map.map_height && (x = -1))
	{
		all.mapaa[cont] = ft_enquadro(all.mapaa[cont], width);
		all.map.map_width = width;
		cont++;
	}
	all = ft_convertemapa(all);
	return (all);
}
