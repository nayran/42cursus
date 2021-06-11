/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caso_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:05:20 by nasimon-          #+#    #+#             */
/*   Updated: 2021/04/20 16:47:20 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_caso_s(char *s, t_flags flags)
{
	int	count;

	flags.tipo = 2;
	count = 0;
	if (s == NULL)
		s = ("(null)");
	if (flags.ponto < 0)
		flags.ponto = (int)ft_strlen(s);
	if (flags.menos)
		count += ft_putstr(s, flags);
	count += ft_flags_compr(flags, ft_strlen(s), 0);
	if (!flags.menos)
		count += ft_putstr(s, flags);
	return (count);
}
