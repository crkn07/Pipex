/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:44:51 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/31 15:54:35 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	int		i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			if (!i++)
				aux = ft_lstnew((*f)(lst->content));
			else
				ft_lstadd_back(&aux, ft_lstnew((*f)(lst->content)));
			lst = lst->next;
		}
		if (0)
			(del)(lst->content);
		return (aux);
	}
	return (0);
}