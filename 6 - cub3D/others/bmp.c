/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:44:38 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 02:44:29 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_bmpheader(t_godfather *all, int fd, int size)
{
	unsigned char	header_buf[54];

	ft_bzero(header_buf, sizeof(header_buf));
	header_buf[0] = (unsigned char)('B');
	header_buf[1] = (unsigned char)('M');
	ft_memcpy(header_buf + 2, &size, sizeof(int));
	header_buf[10] = (unsigned char)(54);
	header_buf[14] = (unsigned char)(40);
	ft_memcpy(header_buf + 18, &all->wx, sizeof(int));
	ft_memcpy(header_buf + 22, &all->wy, sizeof(int));
	header_buf[26] = (unsigned char)(1);
	header_buf[28] = (unsigned char)(24);
	return ((write(fd, header_buf, 54) == 54) ? 10 : 2);
}

static int	ft_bmpdata(t_godfather *all, int fd, ssize_t pad_size)
{
	int						x;
	int						y;
	int						color;
	int						rgb;
	const unsigned char		padding[3] = {0};

	y = all->wy - 1;
	while (y > -1)
	{
		x = 0;
		while (x < all->wx)
		{
			color = all->img.addr[x + y * all->wx];
			rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
			if (write(fd, &rgb, 3) != 3)
				return (2);
			if (pad_size && write(fd, padding, pad_size) != pad_size)
				return (2);
			x++;
		}
		y--;
	}
	return (10);
}

int			ft_bmp(t_godfather *all)
{
	int		fd;
	int		size;
	ssize_t	pad_size;

	if ((fd = open("cub3d.bmp", O_WRONLY | O_CREAT, 0644)) < 0)
		return (2);
	ft_frame(all, &all->cam);
	pad_size = (4 - (all->wx * 3) % 4) % 4;
	size = 54 + ((3 * all->wx) + pad_size) * all->wy;
	if (ft_bmpheader(all, fd, size) != 10)
		return (2);
	if (ft_bmpdata(all, fd, pad_size) != 10)
		return (2);
	close(fd);
	return (10);
}
