/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_rmstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:40:19 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/08 15:02:54 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_free_rmstr(char *str, int i, int j)
{
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(tmp = ft_strnew(ft_strlen(str) - i + j + 1)))
		return (NULL);
	while (str[x])
	{
		if (x == i)
			while (x <= j && str[x])
				x++;
		tmp[y++] = str[x++];
	}
	tmp[y] = '\0';
	return (tmp);
}
