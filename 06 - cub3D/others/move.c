/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:43:18 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 04:23:13 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move2(char c, int **map, t_cam *cam)
{
	if (c == 'r')
	{
		if (!map[(int)cam->pos_y][(int)(cam->pos_x - cam->dir_y * cam->ms * 3)])
			cam->pos_x -= cam->dir_y * (cam->ms / 2);
		if (!map[(int)(cam->pos_y + cam->dir_x * cam->ms * 3)][(int)cam->pos_x])
			cam->pos_y += cam->dir_x * (cam->ms / 2);
	}
	if (c == 'l')
	{
		if (!map[(int)cam->pos_y][(int)(cam->pos_x + cam->dir_y * cam->ms * 3)])
			cam->pos_x += cam->dir_y * (cam->ms / 2);
		if (!map[(int)(cam->pos_y - cam->dir_x * cam->ms * 3)][(int)cam->pos_x])
			cam->pos_y -= cam->dir_x * (cam->ms / 2);
	}
}

void	ft_move(char c, int **map, t_cam *cam)
{
	if (c == 'u')
	{
		if (!map[(int)cam->pos_y][(int)(cam->pos_x + cam->dir_x * cam->ms * 3)])
			cam->pos_x += cam->dir_x * cam->ms;
		if (!map[(int)(cam->pos_y + cam->dir_y * cam->ms * 3)][(int)cam->pos_x])
			cam->pos_y += cam->dir_y * cam->ms;
	}
	if (c == 'd')
	{
		if (!map[(int)cam->pos_y][(int)(cam->pos_x - cam->dir_x * cam->ms * 3)])
			cam->pos_x -= cam->dir_x * (cam->ms / 2);
		if (!map[(int)(cam->pos_y - cam->dir_y * cam->ms * 3)][(int)cam->pos_x])
			cam->pos_y -= cam->dir_y * (cam->ms / 2);
	}
	ft_move2(c, map, cam);
}

int		key_press(int keycode, t_godfather *all)
{
	if (keycode == 13 || keycode == 119 || keycode == 126)
		all->move.up = 1;
	else if (keycode == 1 || keycode == 115 || keycode == 125)
		all->move.down = 1;
	else if (keycode == 2 || keycode == 100)
		all->move.right = 1;
	else if (keycode == 0 || keycode == 97)
		all->move.left = 1;
	else if (keycode == 123 || keycode == 65361)
		all->move.r_left = 1;
	else if (keycode == 124 || keycode == 65363)
		all->move.r_right = 1;
	else if (keycode == 53 || keycode == 65307)
		ft_quit(all);
	return (0);
}

int		key_release(int keycode, t_godfather *all)
{
	if (keycode == 13 || keycode == 119 || keycode == 126)
		all->move.up = 0;
    else if (keycode == 1 || keycode == 115 || keycode == 125)
		all->move.down = 0;
	else if (keycode == 2 || keycode == 100)
		all->move.right = 0;
	else if (keycode == 0 || keycode == 97)
		all->move.left = 0;
	else if (keycode == 123 || keycode == 65361)
		all->move.r_left = 0;
	else if (keycode == 124 || keycode == 65363)
		all->move.r_right = 0;
	return (0);
}

void	ft_rotate(char c, t_cam *cam)
{
	double	dir_x;
	double	plane_x;

	if (c == 'r')
	{
		dir_x = cam->dir_x;
		cam->dir_x = dir_x * cos(cam->rs) - cam->dir_y * sin(cam->rs);
		cam->dir_y = dir_x * sin(cam->rs) + cam->dir_y * cos(cam->rs);
		plane_x = cam->plane_x;
		cam->plane_x = plane_x * cos(cam->rs) - cam->plane_y * sin(cam->rs);
		cam->plane_y = plane_x * sin(cam->rs) + cam->plane_y * cos(cam->rs);
	}
	if (c == 'l')
	{
		dir_x = cam->dir_x;
		cam->dir_x = dir_x * cos(-cam->rs) - cam->dir_y * sin(-cam->rs);
		cam->dir_y = dir_x * sin(-cam->rs) + cam->dir_y * cos(-cam->rs);
		plane_x = cam->plane_x;
		cam->plane_x = plane_x * cos(-cam->rs) - cam->plane_y * sin(-cam->rs);
		cam->plane_y = plane_x * sin(-cam->rs) + cam->plane_y * cos(-cam->rs);
	}
}
