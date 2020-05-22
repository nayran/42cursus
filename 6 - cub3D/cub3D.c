/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <nayran@nayran.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 18:44:12 by nasimon-          #+#    #+#             */
/*   Updated: 2020/05/22 18:53:29 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_godfather	all;
	int			i;
	char		*c;
	int			x;
	int			y;

	c = argv[1];
	i = 0;
	x = 0;
	all = ft_lecube(c);
	printf("Errors: %d\n", all.caso.error);
	while (x < all.caso.map_height)
	{
		y = 0;
		while (y < all.caso.map_width)
		{
			if (ft_isalpha(all.caso.final_map[x][y]))
				printf("%c", all.caso.final_map[x][y++]);
			printf("%d", all.caso.final_map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	return (0);
}
