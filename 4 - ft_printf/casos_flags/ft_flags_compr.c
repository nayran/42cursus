/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_comprimento.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:21:13 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:32:43 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_flags_comprimento2(int i, t_flags flags, char c)
{
	if (flags.bool_ponto && flags.ponto < flags.comprimento)
	{
		while (i < flags.ponto)
		{
			ft_putchar(c);
			i++;
		}
		while (i < flags.comprimento)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (i < flags.comprimento)
		{
			ft_putchar(c);
			i++;
		}
	}
	if (flags.bool_intmin && flags.zero)
		i -= 1;
	return (i);
}

int			ft_flags_compr(t_flags flags, size_t len, int n)
{
	int		i;
	char	c;

	if (n == -1 && flags.bool_intmin == 0)
	{
		if ((flags.ponto >= flags.comprimento || (int)len >= flags.comprimento
					|| ((flags.comprimento > (int)len)
						&& flags.bool_ponto == 0)))
			ft_putchar('-');
	}
	if (flags.bool_ponto && flags.ponto < (int)len && flags.tipo == 2)
		len = flags.ponto;
	i = len;
	if (flags.zero)
		c = '0';
	else
		c = ' ';
	return (ft_flags_comprimento2(i, flags, c) - len);
}
