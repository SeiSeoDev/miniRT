/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:06:22 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/06 15:05:01 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	if (!(p = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		p->content = NULL;
	else
		p->content = content;
	p->next = NULL;
	return (p);
}
