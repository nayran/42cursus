/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlychr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:09:36 by nayran            #+#    #+#             */
/*   Updated: 2020/05/21 23:44:09 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_onlychr(char *str, char *c)
{
	int x;
	int y;
	int k;

	x = 0;
	k = (int)ft_strlen(c);
	while (str[x])
	{
		y = -1;
		while (c[++y])
			if (str[x] == c[y])
				break ;
		if (k == y)
			return (1);
		x++;
	}
	return (0);
}
