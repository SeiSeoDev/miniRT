/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:24:26 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/19 13:59:31 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(int x, char *s1, char *s2)
{
	if (x == 1)
		free(s1);
	else if (x == 2)
		free(s2);
	else if (x == 3)
	{
		free(s1);
		free(s2);
	}
}

char		*ft_free_join(char *s1, char *s2, int x)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			p[i++] = s2[j++];
	p[i] = '\0';
	ft_free(x, s1, s2);
	return (p);
}
