/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapeamento.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 00:19:05 by nayran            #+#    #+#             */
/*   Updated: 2020/05/26 14:35:30 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_south(t_godfather all, int cont)
{
	int x;

	x = 0;
	while (all.mapaa[cont][x])
	{
		if (all.mapaa[cont][x] == ' ')
			if (all.mapaa[cont + 1][x] == '0')
				return (1);
		x++;
	}
	return (0);
}

int			ft_north(t_godfather all, int cont)
{
	int x;

	x = 0;
	while (all.mapaa[cont][x])
	{
		if (all.mapaa[cont][x] == ' ')
			if (all.mapaa[cont - 1][x] == '0')
				return (1);
		x++;
	}
	return (0);
}

int			ft_weea(t_godfather all, int cont)
{
	int x;

	x = 0;
	while (all.mapaa[cont][x])
	{
		if (all.mapaa[cont][x] == ' ')
		{
			if (all.mapaa[cont][x + 1] == '0')
				return (1);
			if (x > 0)
				if (all.mapaa[cont][x - 1] == '0')
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
	while (cont < all.map.map_height)
	{
		if (cont == 0)
		{
			if (ft_south(all, cont))
				return (1);
		}
		if ((cont + 1) == all.map.map_height)
		{
			if (ft_north(all, cont))
				return (1);
		}
		if (cont > 0 && (cont + 1) != all.map.map_height)
			if (ft_weea(all, cont) || ft_north(all, cont) ||
					ft_south(all, cont))
				return (1);
		cont++;
	}
	return (0);
}

int			ft_mapeamento(t_godfather all)
{
	int cont;
	int width;

	cont = 0;
	while (cont < all.map.map_height)
	{
		width = ft_strlen(all.mapaa[cont]) - 1;
		if ((cont == 0 || (cont + 1) == all.map.map_height)
				&& ft_onlychr(all.mapaa[cont], " 1"))
			return (1);
		if (all.mapaa[cont][width] != 49)
			return (1);
		if (all.mapaa[cont][0] != 49 && all.mapaa[cont][0] != ' ')
			return (1);
		cont++;
	}
	return (ft_mapeamento2(all));
}
