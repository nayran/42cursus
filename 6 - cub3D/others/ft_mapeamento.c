/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapeamento.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 00:19:05 by nayran            #+#    #+#             */
/*   Updated: 2020/05/22 14:21:12 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_south(t_godfather all, int cont)
{
	int x;

	x = 0;
	while (all.mapa[cont].line[x])
	{
		if (all.mapa[cont].line[x] == ' ')
			if (all.mapa[cont + 1].line[x] == '0')
				return (1);
		x++;
	}
	return (0);
}

int			ft_north(t_godfather all, int cont)
{
	int x;

	x = 0;
	while (all.mapa[cont].line[x])
	{
		if (all.mapa[cont].line[x] == ' ')
			if (all.mapa[cont - 1].line[x] == '0')
				return (1);
		x++;
	}
	return (0);
}

int			ft_weea(t_godfather all, int cont)
{
	int x;

	x = 0;
	while (all.mapa[cont].line[x])
	{
		if (all.mapa[cont].line[x] == ' ')
		{
			if (all.mapa[cont].line[x + 1] == '0')
				return (1);
			if (x > 0)
				if (all.mapa[cont].line[x - 1] == '0')
					return (1);
		}
		x++;
	}
	return (0);
}

int			ft_mapeamento2(t_godfather all)
{
	int cont;

	cont = 0;
	while (cont < all.caso.map_height)
	{
		if (cont == 0)
		{
			if (ft_south(all, cont))
				return (1);
		}
		if ((cont + 1) == all.caso.map_height)
		{
			if (ft_north(all, cont))
				return (1);
		}
		if (cont > 0 && (cont + 1) != all.caso.map_height)
			if (ft_weea(all, cont) || ft_north(all, cont) ||
					ft_south(all, cont))
				return (1);
		cont++;
	}
	return (0);
}

t_godfather	ft_mapafinal(t_godfather all)
{
	int cont;
	int x;
	int width;

	width = 0;
	cont = 0;
	while (cont < all.caso.map_height)
	{
		if (width < all.mapa[cont].width)
			width = all.mapa[cont].width;
		cont++;
	}
	all.caso.map_width = width;
	cont = 0;
	while (cont < all.caso.map_height && (x = -1))
	{
		all.mapa[cont].line = ft_enquadro(all.mapa[cont].line, width);
		all.mapa[cont].width = width;
		cont++;
	}
	all = ft_convertemapa(all);
	return (all);
}
