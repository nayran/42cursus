/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:43:55 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 04:20:24 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_mapsize(t_map *map, const char *line)
{
	while (*line != '\n')
	{
		if (ft_validchar(*line, "102NSEW"))
			map->x++;
		else if (*line == '2')
			map->sprites_nb++;
		else if (*line != ' ')
			return (8);
		line++;
	}
	while (*line)
	{
		if (!ft_validchar(*line, "102NSEW") && *line != ' ' && *line != '\n')
			return (8);
		else if (*line == '2')
			map->sprites_nb++;
		else if (*line == '\n')
			map->y++;
		line++;
	}
	return (10);
}

static int		ft_mapcheck(t_map *map)
{
	int	x;
	int	y;
	int	start;

	start = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if ((y == 0 || y == map->y - 1) && map->map[y][x] != 1)
				return (10);
			if ((x == 0 || x == map->x - 1) && map->map[y][x] != 1)
				return (10);
			if (ft_mapstart(map, x, y))
				start++;
			x++;
		}
		y++;
	}
	return (start == 1 ? 10 : 8);
}

static void		ft_spritecheck(t_map *map)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 2)
			{
				map->sprites[index].map_x = x + 0.5;
				map->sprites[index].map_y = y + 0.5;
				index++;
			}
			x++;
		}
		y++;
	}
}

int				ft_map(t_map *map, const char *line)
{
	if (ft_mapsize(map, line) != 10)
		return (8);
	if (ft_mapalloc(map) != 10)
		return (8);
	if (ft_mapcpy(map, line) != 10)
	{
		ft_mapfree(map->map, map->y);
		return (8);
	}
	if (ft_mapcheck(map) != 10)
	{
		ft_mapfree(map->map, map->y);
		return (8);
	}
	ft_spritecheck(map);
	return (10);
}
