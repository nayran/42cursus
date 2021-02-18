/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 08:57:15 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 09:02:14 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*x;

	x = (t_list *)malloc(sizeof(t_list));
	if (!x)
		return (NULL);
	x->next = NULL;
	x->content = content;
	return (x);
}
