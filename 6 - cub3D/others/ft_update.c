/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 02:00:12 by nayran            #+#    #+#             */
/*   Updated: 2020/06/08 02:00:40 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_iswall(float x, float y)
{
	int gridx;
	int gridy;

	if (x < 0 || x > g_all.r[0] || y < 0 || y > g_all.r[1])
		return (1);
	gridx = floor(x / g_tilesize);
	gridy = floor(y / g_tilesize);
	return (g_all.map.map[gridy][gridx] != 0);
}

void	ft_moveplayer(float deltatime)
{
	float movestep;
	float newplayerx;
	float newplayery;

	g_all.player.rotationangle += g_all.player.turndirection *
		g_all.player.turnspeed * deltatime;
	movestep = g_all.player.walkdirection * g_all.player.walkspeed * deltatime;
	newplayerx = g_all.player.x + cos(g_all.player.rotationangle) * movestep;
	newplayery = g_all.player.y + sin(g_all.player.rotationangle) * movestep;
	if (!ft_iswall(newplayerx, newplayery))
	{
		g_all.player.x = newplayerx;
		g_all.player.y = newplayery;
	}
}

void	ft_update(void)
{
	float deltatime;

	deltatime = 0.03;
	ft_moveplayer(deltatime);
	ft_castallrays();
	ft_render();
}
