/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caso_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:56:50 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:22:52 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_caso_c(char c, t_flags flags)
{
	int	l;

	if (flags.menos)
		ft_putchar(c);
	l = ft_flags_compr(flags, 1, 0);
	if (!flags.menos)
		ft_putchar(c);
	return (l + 1);
}
