/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caso_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:20:53 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:23:44 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_caso_x2(char *str, t_flags flags, int count)
{
	if (str[0] == '0' && flags.ponto == 0 && flags.bool_ponto == 1)
		return (0);
	count = ft_strlen(str);
	if (flags.bool_ponto && flags.ponto > (int)ft_strlen(str))
		count += flags.ponto - ft_strlen(str);
	if (flags.menos)
		ft_putstr_spec_x(str, flags);
	count += ft_flags_compr(flags, count, 0);
	if (!flags.menos)
		ft_putstr_spec_x(str, flags);
	return (count);
}

int			ft_caso_x(int x, t_flags flags, char caso)
{
	char			*str;
	int				count;
	unsigned int	u;

	u = x;
	count = 0;
	if (flags.ponto < 0)
		flags.bool_ponto = 0;
	if (flags.bool_ponto && !flags.ponto && x == 0)
	{
		if (!flags.comprimento)
			return (count);
		else
			return (ft_flags_compr(flags, count, flags.tipo));
	}
	if (caso == 'x')
		str = ft_uitoa_base(u, LOWER_BASE);
	else
		str = ft_uitoa_base(u, UPPER_BASE);
	return (ft_caso_x2(str, flags, count));
}

int			ft_putstr_spec_x(char *s, t_flags flags)
{
	int zeros;
	int count;
	int i;

	i = 0;
	zeros = flags.ponto - ft_strlen(s);
	count = zeros;
	while (zeros > 0)
	{
		ft_putchar('0');
		zeros--;
	}
	while (s[i])
		ft_putchar(s[i++]);
	return (count + i);
}
