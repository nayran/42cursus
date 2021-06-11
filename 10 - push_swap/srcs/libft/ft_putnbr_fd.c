/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:53:48 by nasimon-          #+#    #+#             */
/*   Updated: 2021/04/20 16:28:31 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cont(unsigned int aux)
{
	int	x;

	x = 1;
	while (aux > 9)
	{
		aux = aux / 10;
		x++;
	}
	return (x);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			x;
	int				cont;
	unsigned int	aux;
	int				pot;

	pot = 1;
	aux = n;
	if (n < 0)
		aux = 0 - n;
	cont = ft_cont(aux);
	while (--cont)
		pot *= 10;
	if (n < 0)
		write(fd, "-", 1);
	while (pot >= 1)
	{
		x = aux / pot + '0';
		write(fd, &x, 1);
		aux = aux % pot;
		pot = pot / 10;
	}
}
