/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caso_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:20:08 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:24:54 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_caso_p2(char *str, t_flags flags, int count)
{
	if (flags.menos)
	{
		write(1, "0x", 2);
		ft_putstr_spec(str, flags, 0);
	}
	count += ft_flags_compr(flags, count + 2, 0);
	if (!flags.menos)
	{
		write(1, "0x", 2);
		ft_putstr_spec(str, flags, 0);
	}
	return (count + 2);
}

int			ft_caso_p(unsigned long int p, t_flags flags)
{
	int		count;
	char	*str;

	str = ft_uitoa_base(p, LOWER_BASE);
	if (flags.ponto < 0 && !(count = 0))
		flags.bool_ponto = 0;
	count = ft_strlen(str);
	if (flags.bool_ponto && flags.ponto > (int)ft_strlen(str))
		count += flags.ponto - ft_strlen(str);
	if (flags.bool_ponto && !flags.ponto && p == 0)
	{
		if (!flags.comprimento)
		{
			write(1, "0x", 2);
			return (count + 1);
		}
		else
		{
			flags.tipo = 0;
			count += ft_flags_compr(flags, count + 1, flags.tipo);
			write(1, "0x", 2);
			return (count + 1);
		}
	}
	return (ft_caso_p2(str, flags, count));
}
