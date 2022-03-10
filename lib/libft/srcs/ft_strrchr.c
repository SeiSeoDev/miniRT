/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:27:07 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 16:45:25 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	i = ft_strlen(s);
	p = NULL;
	while (j <= i)
	{
		if (s[j] == (char)c)
			p = (char *)&s[j];
		j++;
	}
	return (p);
}
