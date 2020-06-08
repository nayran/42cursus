/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trata_casos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:55:58 by nayran            #+#    #+#             */
/*   Updated: 2020/05/27 15:39:11 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_godfather	ft_tratageral2(t_godfather all, char *c, char *tipo)
{
	if (ft_strstr(tipo, "NO") > 0)
		all.no = ft_strdup(c);
	else if (ft_strstr(tipo, "SO") > 0)
		all.so = ft_strdup(c);
	else if (ft_strstr(tipo, "WE") > 0)
		all.we = ft_strdup(c);
	else if (ft_strstr(tipo, "EA") > 0)
		all.ea = ft_strdup(c);
	else if (ft_strstr(tipo, "S") > 0)
		all.s = ft_strdup(c);
	return (all);
}

t_godfather	ft_tratageral(char *line, char *tipo, t_godfather all)
{
	int		x;
	int		y;
	int		k;
	char	*c;

	x = 0;
	y = 0;
	k = ft_strlen(line);
	while (line[x + y] && k)
	{
		while (line[x] < 33 || line[x] == *tipo)
		{
			if (ft_strlen(tipo) > 1)
				if (line[x] == *tipo && line[x + 1] == *(tipo + 1))
					x++;
			x++;
		}
		while (line[x + y] && ft_isascii(line[x + y]) > 0)
			y++;
		c = ft_substr(line, x, y);
		k--;
	}
	all = ft_tratageral2(all, c, tipo);
	return (all);
}

t_godfather	ft_tratafc(char *line, t_godfather all, char cas)
{
	int		x;
	int		y;
	char	*c;
	int		k;

	k = 0;
	y = 0;
	x = 0;
	while (k < 3)
	{
		x += y;
		while (line[x] && (ft_isdigit(line[x]) == 0 || line[x] == ','))
			x++;
		x--;
		while (line[x + y] && (ft_isdigit(line[x + y]) > 0 &&
					line[x + y] != ','))
			y++;
		c = ft_substr(line, x, y);
		if (cas == 'F')
			all.f[k] = ft_atoi(c);
		if (cas == 'C')
			all.c[k] = ft_atoi(c);
		k++;
	}
	return (all);
}

t_godfather	ft_trata_r(char *line, t_godfather all)
{
	int		x;
	int		y;
	char	*c;
	int		k;

	k = 0;
	x = 0;
	y = 0;
	while (k < 2 && line[x + y])
	{
		x += y;
		while (ft_isdigit(line[x + y]) == 0)
			x++;
		while (ft_isdigit(line[x + y]) > 0)
			y++;
		c = ft_substr(line, x, y);
		all.r[k] = ft_atoi(c);
		k++;
	}
	return (all);
}

t_godfather	ft_tratacasos(char *line, t_godfather all)
{
	if (ft_strstr(line, "R") && (all.mapaa == NULL))
		all = ft_trata_r(line, all);
	else if (ft_strstr(line, "NO") && (all.mapaa == NULL))
		all = ft_tratageral(line, "NO", all);
	else if (ft_strstr(line, "SO") && (all.mapaa == NULL))
		all = ft_tratageral(line, "SO", all);
	else if (ft_strstr(line, "WE") && (all.mapaa == NULL))
		all = ft_tratageral(line, "WE", all);
	else if (ft_strstr(line, "EA") && (all.mapaa == NULL))
		all = ft_tratageral(line, "EA", all);
	else if (ft_strstr(line, "S") && (all.mapaa == NULL))
		all = ft_tratageral(line, "S", all);
	else if (ft_strstr(line, "F") && (all.mapaa == NULL))
		all = ft_tratafc(line, all, 'F');
	else if (ft_strstr(line, "C") && (all.mapaa == NULL))
		all = ft_tratafc(line, all, 'C');
	else if (ft_strstr(line, "1"))
		all = ft_copiamapa(line, all);
	return (all);
}
