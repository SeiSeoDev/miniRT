/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:05:26 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/19 13:34:41 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char			*p;
	int				unit;
	unsigned int	nb;
	int				i;

	i = 0;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	unit = ft_nbrlen(nb);
	if (!(p = (char *)malloc(unit + 1 + ft_neg(n))))
		return (NULL);
	while (unit > 0)
	{
		p[i++] = nb % 10 + '0';
		nb /= 10;
		unit--;
	}
	if (n < 0)
		p[i++] = '-';
	p[i] = '\0';
	p = ft_strrev(p);
	return (p);
}
