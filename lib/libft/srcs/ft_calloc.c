/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:38:32 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/06 15:02:45 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = (void *)malloc(sizeof(void) * size * count)))
		return (NULL);
	if (!(ptr = ft_memset(ptr, 0, count * size)))
		return (NULL);
	return (ptr);
}
