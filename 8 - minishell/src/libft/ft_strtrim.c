/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 01:07:31 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 07:14:59 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		l;
	char const	*first_char;
	char const	*last_char;

	if (s1 == NULL || set == NULL)
		return (NULL);
	l = 0;
	first_char = s1;
	last_char = s1 + (ft_strlen(s1) - 1);
	while (*(set + l) && (first_char <= last_char))
	{
		if (*first_char == *(set + l) || *last_char == *(set + l))
		{
			if (*first_char == *(set + l))
				first_char++;
			if (*last_char == *(set + l))
				last_char--;
			l = 0;
		}
		else
			l++;
	}
	while (first_char + l <= last_char)
		l++;
	return (ft_substr(first_char, 0, l));
}
