/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 01:49:26 by nayran            #+#    #+#             */
/*   Updated: 2020/06/08 02:09:16 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			exit_hook(void)
{
	mlx_destroy_window(g_view.mlx, g_view.window);
	exit(0);
}

int			key_pressed(int key)
{
	if (key == 53)
		exit_hook();
	if (key == 13)
		g_all.player.walkdirection += 1;
	else if (key == 0)
		g_all.player.turndirection -= 1;
	else if (key == 1)
		g_all.player.walkdirection -= 1;
	else if (key == 2)
		g_all.player.turndirection += 1;
	else if (key == 123)
		g_all.player.turndirection -= 1;
	else if (key == 124)
		g_all.player.turndirection += 1;
	else
		printf("%d\n", key);
	ft_update();
	return (0);
}

int			key_released(int key)
{
	if (key == 13 || key == 1)
		g_all.player.walkdirection = 0;
	else if (key == 0 || key == 2 || key == 123 || key == 124)
		g_all.player.turndirection = 0;
	return (0);
}

void		ft_sethooks(void)
{
	mlx_hook(g_view.window, 2, 0, key_pressed, &g_view);
	mlx_hook(g_view.window, 3, 0, key_released, &g_view);
	mlx_hook(g_view.window, 17, 0, exit_hook, &g_view);
}
