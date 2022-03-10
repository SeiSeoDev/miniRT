/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:55:38 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/11 17:57:19 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	if (needle[0] == '\0' || !needle)
		return ((char *)str);
	while (str[i] && i <= len)
	{
		j = 0;
		while (str[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				p = (char *)(str + i);
				return (p);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
