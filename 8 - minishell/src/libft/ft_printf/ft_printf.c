/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:06:46 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:43:01 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *s, ...)
{
	va_list args;
	t_flags flags;
	int		l;
	int		count;

	va_start(args, s);
	l = 0;
	count = 0;
	while (s[l])
	{
		if (s[l] == '%')
		{
			l++;
			flags = ft_start_struct();
			while (s[l] && ft_strchr(FLAGS, s[l]))
				flags = ft_trata_flags(&s[l++], args, flags);
			if (!s[l])
				return (0);
			count += ft_trata_casos(s[l++], args, flags);
		}
		else if (++count)
			ft_putchar(s[l++]);
	}
	return (count);
}

t_flags		ft_start_struct(void)
{
	t_flags	flags;

	flags.menos = 0;
	flags.comprimento = 0;
	flags.bool_ponto = 0;
	flags.ponto = 0;
	flags.zero = 0;
	flags.tipo = 0;
	flags.bool_intmin = 0;
	return (flags);
}

t_flags		ft_trata_flags(const char *s, va_list args, t_flags flags)
{
	if (*s == '0' && flags.menos == 0 && flags.comprimento == 0)
		flags.zero = 1;
	if (*s == '*')
		flags = ft_trata_comprimento(args, flags);
	if (*s == '.')
		flags.bool_ponto = 1;
	if (*s == '-')
	{
		flags.menos = 1;
		flags.zero = 0;
	}
	if (ft_strchr(NUMEROS, *s))
	{
		if (flags.bool_ponto)
			flags.ponto = (flags.ponto * 10) + (*s - '0');
		else
			flags.comprimento = (flags.comprimento * 10) + (*s - '0');
	}
	return (flags);
}

t_flags		ft_trata_comprimento(va_list args, t_flags flags)
{
	if (flags.bool_ponto)
		flags.ponto = va_arg(args, int);
	else
		flags.comprimento = va_arg(args, int);
	while (flags.comprimento < 0)
	{
		flags.menos = 1;
		flags.comprimento *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int			ft_trata_casos(char c, va_list args, t_flags flags)
{
	if (c == 'c')
		return (ft_caso_c(va_arg(args, int), flags));
	if (c == 's')
		return (ft_caso_s(va_arg(args, char *), flags));
	if (c == 'd' || c == 'i')
		return (ft_caso_d(va_arg(args, int), flags));
	if (c == 'x' || c == 'X')
		return (ft_caso_x(va_arg(args, int), flags, c));
	if (c == 'p')
		return (ft_caso_p(va_arg(args, unsigned long int), flags));
	if (c == 'u')
		return (ft_caso_u(va_arg(args, int), flags));
	if (c == '%')
		return (ft_caso_pct(flags));
	return (0);
}
