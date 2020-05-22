/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:53:00 by nayran            #+#    #+#             */
/*   Updated: 2020/05/21 16:02:15 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstr(char *str, char *str2)
{
	int x;
	int y;
	int k;

	x = 0;
	k = (int)ft_strlen(str2);
	while (str[x])
	{
		y = 0;
		while (str2[y] == str[x + y])
		{
			if (y == k - 1)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
