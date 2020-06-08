/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 01:19:48 by nayran            #+#    #+#             */
/*   Updated: 2020/06/08 01:48:10 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_drawsquare(int x, int y, int size, int color)
{
	int y1;
	int x1;

	y1 = y;
	while (y1 <= size + y && y1 < g_all.r[1])
	{
		x1 = x;
		while (x1 <= size + x && x1 < g_all.r[0])
		{
			ft_pixelput(x1, y1, color);
			x1++;
		}
		y1++;
	}
}

void	ft_pixelput(int x, int y, int color)
{
	char *dest;

	dest = g_img.img_addr + (y * g_img.line_length + x * (g_img.bpp / 8));
	*(unsigned int *)dest = color;
}

int		abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

void	ft_drawline(int x0, int y0, int x1, int y1)
{
	int		steps;
	float	x;
	float	y;
	int		i;

	i = 0;
	steps = abs(x1 - x0) > abs(y1 - y0) ? abs(x1 - x0) : abs(y1 - y0);
	x = x0;
	y = y0;
	while (i <= steps)
	{
		ft_pixelput(round(x), round(y), 0xff0000);
		x += (float)(x1 - x0) / steps;
		y += (float)(y1 - y0) / steps;
		i++;
	}
}
