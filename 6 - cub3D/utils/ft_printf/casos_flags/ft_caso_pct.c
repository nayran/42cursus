/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caso_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:17:44 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 19:24:27 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_caso_pct(t_flags flags)
{
	int		count;

	if (flags.menos)
		write(1, "%", 1);
	count = ft_flags_compr(flags, 1, 0);
	if (!flags.menos)
		write(1, "%", 1);
	return (count + 1);
}
