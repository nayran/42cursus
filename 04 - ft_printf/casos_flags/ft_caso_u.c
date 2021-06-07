/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caso_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:28:54 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:28:58 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_caso_u2(char *str, t_flags flags, int count)
{
	count = ft_strlen(str);
	if (flags.bool_ponto && flags.ponto > (int)ft_strlen(str))
		count += flags.ponto - ft_strlen(str);
	if (flags.menos)
		ft_putstr_spec_u(str, flags);
	count += ft_flags_compr(flags, count, 0);
	if (!flags.menos)
		ft_putstr_spec_u(str, flags);
	return (count);
}

int			ft_caso_u(int u, t_flags flags)
{
	unsigned long	i;
	char			*str;
	int				count;

	i = u;
	count = 0;
	if (flags.ponto < 0)
		flags.bool_ponto = 0;
	if (u < 0)
		i = ULONG_MAX + 1 + u;
	str = ft_uitoa(i);
	if (flags.bool_ponto && !flags.ponto && u == 0)
	{
		if (!flags.comprimento)
			return (count);
		else
			return (ft_flags_compr(flags, count, flags.tipo));
	}
	return (ft_caso_u2(str, flags, count));
}

int			ft_putstr_spec_u(char *s, t_flags flags)
{
	int	zeros;
	int	count;
	int	i;

	i = 0;
	zeros = flags.ponto - ft_strlen(s);
	count = zeros;
	while (zeros > 0)
	{
		ft_putchar('0');
		zeros--;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (count + i);
}
