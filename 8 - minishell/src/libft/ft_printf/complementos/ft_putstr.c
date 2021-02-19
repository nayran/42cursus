/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:59:52 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:33:31 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s, t_flags fl)
{
	int i;

	i = 0;
	if (fl.ponto < 0)
		fl.ponto = (int)ft_strlen(s);
	if (s == NULL)
		return (0);
	if (!fl.bool_ponto)
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	else
	{
		while (s[i] != '\0' && i < fl.ponto)
			ft_putchar(s[i++]);
	}
	return (i);
}
