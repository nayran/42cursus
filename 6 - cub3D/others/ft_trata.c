/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:03:34 by nayran            #+#    #+#             */
/*   Updated: 2020/05/22 13:54:22 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		all.caso.r[k] = ft_atoi(c);
		k++;
	}
	return (all);
}

t_godfather	ft_tratageral2(t_godfather all, char *c, char *tipo)
{
	if (ft_strstr(tipo, "NO") > 0)
		all.caso.no = c;
	else if (ft_strstr(tipo, "SO") > 0)
		all.caso.so = c;
	else if (ft_strstr(tipo, "WE") > 0)
		all.caso.we = c;
	else if (ft_strstr(tipo, "EA") > 0)
		all.caso.ea = c;
	else if (ft_strstr(tipo, "S") > 0)
		all.caso.s = c;
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
		while (ft_isdigit(line[x]) == 0 || line[x] == ',')
			x++;
		while (ft_isdigit(line[x + y]) > 0 && line[x + y] != ',')
			y++;
		c = ft_substr(line, x, y);
		if (cas == 'F')
			all.caso.f[k] = ft_atoi(c);
		if (cas == 'C')
			all.caso.c[k] = ft_atoi(c);
		k++;
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