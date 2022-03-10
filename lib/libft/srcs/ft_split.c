/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:56:52 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/11 21:02:38 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_free_all(char **tab, int x)
{
	int	i;

	i = 0;
	while (i < x)
		free(tab[i++]);
	free(tab);
}

static	char	**ft_malloctab(char **tab, const char *s, char c, int x)
{
	int		j;
	int		i;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		if (j != 0)
		{
			if (!(tab[x] = (char *)malloc(j + 1)))
			{
				ft_free_all(tab, x);
				return (NULL);
			}
			x++;
		}
		if (s[i])
			i++;
	}
	return (tab);
}

static	void	ft_filtab(char **tab, const char *s, char c)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i])
				tab[x][j++] = s[i++];
			tab[x++][j] = '\0';
		}
		if (s[i])
			i++;
	}
	tab[x] = NULL;
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	if (!(tab = ft_malloctab(tab, s, c, 0)))
		return (NULL);
	ft_filtab(tab, s, c);
	return (tab);
}
