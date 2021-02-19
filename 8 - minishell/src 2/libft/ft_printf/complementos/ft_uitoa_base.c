/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:47:35 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 16:06:02 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_digit_counter(uintmax_t n)
{
	if (!(n / 16))
		return (1);
	else
		return (ft_digit_counter(n / 16) + 1);
}

char			*ft_uitoa_base(uintmax_t n, const char *base)
{
	char	*s;
	size_t	len;
	size_t	base_len;

	base_len = 16;
	len = ft_digit_counter(n);
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (NULL);
	s[len] = '\0';
	while (len--)
	{
		s[len] = base[n % base_len];
		n /= base_len;
	}
	return (s);
}
