/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:50:37 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 11:48:17 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*x;

	while (*lst && del)
	{
		x = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = x;
	}
	lst = NULL;
}
