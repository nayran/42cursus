/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:44:48 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 03:38:44 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		**ft_mapfree(int **map, int index_stop)
{
	int		index;

	index = 0;
	while (index < index_stop)
	{
		free(map[index]);
		index++;
	}
	free(map);
	return (NULL);
}

void	ft_spritesort(t_sprite *sprites, int spriteqtd)
{
	int			i;
	int			sorted;
	t_sprite	tmp;

	sorted = 1;
	while (sorted)
	{
		i = 0;
		sorted = 0;
		while (i < spriteqtd - 1)
		{
			if (sprites[i].dist < sprites[i + 1].dist)
			{
				tmp = sprites[i];
				sprites[i] = sprites[i + 1];
				sprites[i + 1] = tmp;
				sorted++;
			}
			i++;
		}
	}
}
