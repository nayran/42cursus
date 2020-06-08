/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exactstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 00:24:07 by nayran            #+#    #+#             */
/*   Updated: 2020/05/27 00:28:08 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_exactstr(char *str, char *str2)
{
	if (ft_strlen(str) == ft_strlen(str2))
		if (ft_strstr(str, str2))
			return (1);
	return (0);
}
