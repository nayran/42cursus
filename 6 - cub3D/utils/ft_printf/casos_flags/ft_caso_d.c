/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caso_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:13:51 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:30:25 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_caso_d2(int d, char *s, t_flags flags, int count)
{
	if (flags.bool_ponto && !flags.ponto && d == 0)
	{
		if (!flags.comprimento)
			return (count);
		else
			return (ft_flags_compr(flags, count, flags.tipo));
	}
	else if (d < 0)
		flags.ponto += 1;
	s = ft_itoa(d);
	count += ft_strlen(s);
	if (flags.bool_ponto && flags.ponto > (int)ft_strlen(s))
		count += flags.ponto - ft_strlen(s);
	if (flags.menos)
		ft_putstr_spec(s, flags, d);
	count += ft_flags_compr(flags, count, flags.tipo);
	if (!flags.menos)
		ft_putstr_spec(s, flags, d);
	return (count);
}

int				ft_caso_d(int d, t_flags flags)
{
	int		count;
	char	*s;

	count = 0;
	if (flags.ponto < 0)
		flags.bool_ponto = 0;
	if (d == INT_MIN)
		flags.bool_intmin = 1;
	s = ft_itoa(d);
	if (d < 0 && flags.zero != 0)
	{
		if ((flags.ponto >= flags.comprimento || (int)ft_strlen(s) >=
					flags.comprimento) || (flags.comprimento > (int)ft_strlen(s)
						&& flags.zero == 1 &&
					flags.bool_ponto == 0))
		{
			flags.tipo = -1;
			d *= -1;
			count++;
		}
	}
	return (ft_caso_d2(d, s, flags, count));
}

int				ft_putstr_spec(char *s, t_flags flags, int d)
{
	int zeros;
	int count;
	int i;

	i = 0;
	zeros = flags.ponto - (int)ft_strlen(s);
	if (d < 0 && flags.bool_intmin == 0)
	{
		ft_putchar('-');
		s = ft_itoa(d * -1);
	}
	count = zeros;
	while (zeros-- > 0)
		ft_putchar('0');
	if (flags.bool_ponto && !flags.ponto && s[i] == '0')
		return (count);
	while (s[i])
		ft_putchar(s[i++]);
	return (count + 1);
}
