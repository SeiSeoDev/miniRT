/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:06:18 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/06 15:04:51 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(p = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	tmp = p;
	lst = lst->next;
	while (lst)
	{
		if (!(p->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			break ;
		}
		lst = lst->next;
		p = p->next;
	}
	p = tmp;
	return (p);
}
