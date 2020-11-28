/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:44:14 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 04:23:52 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_skip(const char **file, const char *set)
{
	const char	*aux;

	aux = set;
	while (*aux)
	{
		if (**file == *aux)
		{
			(*file)++;
			aux = set;
		}
		else
			aux++;
	}
}

int		ft_validchar(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		ft_mapstart(t_map *map, int x, int y)
{
	if (map->map[y][x] < 21)
		return (0);
	map->start_x = x;
	map->start_y = y;
	map->start_dir = (char)(map->map[y][x] + 48);
	map->map[y][x] = 0;
	return (1);
}

int		ft_mapalloc(t_map *map)
{
	int		index;

	index = 0;
	if ((map->map = (int**)malloc(sizeof(int*) * map->y)) == NULL)
		return (8);
	while (index < map->y)
	{
		if ((map->map[index] = (int*)malloc(sizeof(int) * map->x)) == NULL)
		{
			ft_mapfree(map->map, index);
			return (8);
		}
		index++;
	}
	if ((map->sprites = malloc(map->sprites_nb * sizeof(t_sprite))) == NULL)
	{
		ft_mapfree(map->map, index);
		return (8);
	}
	return (10);
}

int		ft_mapcpy(t_map *map, const char *file)
{
	int	x;
	int	y;

	y = 0;
	while (*file)
	{
		x = 0;
		while (*file && *file != '\n')
		{
			if (ft_validchar(*file, "102NSEW"))
			{
				map->map[y][x] = *file - 48;
				if (++x > map->x)
					return (8);
			}
			file++;
		}
		if (++y > map->y || x != map->x)
			return (8);
		file++;
	}
	return (y == map->y ? 10 : 8);
}
