/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 02:26:29 by nayran            #+#    #+#             */
/*   Updated: 2020/06/08 05:08:57 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rays *g_rays;

void	horizontal(t_cast *c, float rayangle, int stripid, float *horzwall)
{
	float x;
	float y;

	y = floor(g_all.player.y / g_tilesize) * g_tilesize;
	y += g_rays[stripid].facingdown ? g_tilesize : 0;
	x = g_all.player.x + (y - g_all.player.y) / tan(rayangle);
	c->ystep = g_tilesize;
	c->ystep *= g_rays[stripid].facingup ? -1 : 1;
	c->xstep = g_tilesize / tan(rayangle);
	c->xstep *= (g_rays[stripid].facingleft && c->xstep > 0) ? -1 : 1;
	c->xstep *= (g_rays[stripid].facingright && c->xstep < 0) ? -1 : 1;
	while (x >= 0 && x <= g_all.r[0] && y >= 0 && y <= g_all.r[1])
	{
		c->ytocheck = y + (g_rays[stripid].facingup ? -1 : 0);
		if (x / g_tilesize >= g_all.map.map_width)
			x = (g_all.map.map_width - 1) * g_tilesize;
		if (c->ytocheck / g_tilesize >= g_all.map.map_height)
			c->ytocheck = (g_all.map.map_height - 1) * g_tilesize;
		if (ft_iswall(x, c->ytocheck))
		{
			horzwall[1] = x;
			horzwall[2] = y;
			horzwall[3] = g_all.map.map[(int)floor(c->ytocheck /
					g_tilesize)][(int)floor(x / g_tilesize)];
			horzwall[0] = 1;
			break ;
		}
		x += c->xstep;
		y += c->ystep;
	}
}

void	vertical(t_cast *c, float rayangle, int stripid, float *vertwall)
{
	float x;
	float y;

	x = floor(g_all.player.x / g_tilesize) * g_tilesize;
	x += g_rays[stripid].facingright ? g_tilesize : 0;
	y = g_all.player.y + (x - g_all.player.x) * tan(rayangle);
	c->xstep = g_tilesize;
	c->xstep *= g_rays[stripid].facingleft ? -1 : 1;
	c->ystep = g_tilesize * tan(rayangle);
	c->ystep *= (g_rays[stripid].facingup && c->ystep > 0) ? -1 : 1;
	c->ystep *= (g_rays[stripid].facingdown && c->ystep < 0) ? -1 : 1;
	while (x >= 0 && x <= g_all.r[0] && y >= 0 && y <= g_all.r[1])
	{
		c->xtocheck = x + (g_rays[stripid].facingleft ? -1 : 0);
		if (c->xtocheck / g_tilesize >= g_all.map.map_width)
			c->xtocheck = (g_all.map.map_width - 1) * g_tilesize;
		if (y / g_tilesize >= g_all.map.map_height)
			y = (g_all.map.map_height - 1) * g_tilesize;
		if (ft_iswall(c->xtocheck, y))
		{
			vertwall[1] = x;
			vertwall[2] = y;
			vertwall[3] = g_all.map.map[(int)floor(y /
					g_tilesize)][(int)floor(c->xtocheck / g_tilesize)];
			vertwall[0] = 1;
			break ;
		}
		x += c->xstep;
		y += c->ystep;
	}
}

void	castray(float rayangle, int stripid)
{
	t_cast	*c;
	float	horz[4];
	float	vert[4];
	float	horzdistance;
	float	vertdistance;

	ft_bzero(horz, 4);
	ft_bzero(vert, 4);
	c = (t_cast *)malloc(sizeof(t_cast));
	rayangle = remainder(rayangle, (M_PI * 2));
	if (rayangle < 0)
		rayangle = (2 * M_PI) + rayangle;
	g_rays[stripid].facingdown = rayangle > 0 && rayangle < M_PI;
	g_rays[stripid].facingup = !g_rays[stripid].facingdown;
	g_rays[stripid].facingright = rayangle < M_PI / 2 || rayangle > 1.5 * M_PI;
	g_rays[stripid].facingleft = !g_rays[stripid].facingright;
	horizontal(c, rayangle, stripid, horz);
	vertical(c, rayangle, stripid, vert);
	horzdistance = horz[0] ? sqrt((horz[1] - g_all.player.x) * (horz[1] -
				g_all.player.x) + (horz[2] - g_all.player.y) * (horz[2] -
				g_all.player.y)) : INT_MAX;
	vertdistance = vert[0] ? sqrt((vert[1] - g_all.player.x) * (vert[1] -
				g_all.player.x) + (vert[2] - g_all.player.y) * (vert[2] -
				g_all.player.y)) : INT_MAX;
	if (vertdistance < horzdistance)
	{
		g_rays[stripid].distance = vertdistance;
		g_rays[stripid].wallhitx = vert[1];
		g_rays[stripid].wallhity = vert[2];
		g_rays[stripid].wallhitcontent = vert[3];
		g_rays[stripid].washitvertical = 1;
	}
	else
	{
		g_rays[stripid].distance = horzdistance;
		g_rays[stripid].wallhitx = horz[1];
		g_rays[stripid].wallhity = horz[2];
		g_rays[stripid].wallhitcontent = horz[3];
		g_rays[stripid].washitvertical = 0;
	}
}

void	ft_castallrays(void)
{
	float	rayangle;
	int		stripid;

	rayangle = g_all.player.rotationangle - ((60 * (M_PI / 180)) / 2);
	stripid = -1;
	g_rays = (t_rays *)malloc(sizeof(t_rays) * g_all.r[0]);
	while (++stripid < g_all.r[0])
	{
		castray(rayangle, stripid);
		g_rays[stripid].rayangle = rayangle;
		rayangle += (60 * (M_PI / 180)) / g_all.r[0];
	}
}
