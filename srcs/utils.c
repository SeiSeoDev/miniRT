/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:07:28 by tamigore          #+#    #+#             */
/*   Updated: 2021/02/16 20:16:21 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_v3	rescale_vec(t_v3 vec, int min, int max)
{
	if (vec.x > max)
		vec.x = max;
	if (vec.y > max)
		vec.y = max;
	if (vec.z > max)
		vec.z = max;
	if (vec.x < min)
		vec.x = min;
	if (vec.y < min)
		vec.y = min;
	if (vec.z < min)
		vec.z = min;
	return (vec);
}

char		*ft_strjoindelone(char *s1, char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	result = ft_strnew(len_s1 + len_s2);
	if (!result)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(result, s1, (len_s1 + 1));
		ft_strdel(&s1);
	}
	if (s2)
		ft_strlcpy(result + len_s1, s2, (len_s2 + 1));
	return (result);
}

int			rgb2color(int R, int G, int B)
{
	return ((R<<16)|(G<<8)|B);
}

double		MaxVal(int nb, ...)
{
	double	i;
	double	*x;
	va_list	param;

	i = 0;
	if (!(x = (double *)malloc(sizeof(double) * nb)))
		return (NAN);
	va_start(param, nb);
	while (i < nb)
		x[(int)i++] = va_arg(param, double);
	va_end(param);
	i = *x;
	while (nb-- > 0)
	{
		if (i < *x)
			i = *x;
		x++;
	}
	return (i);
}

void		swap(double *x, double *y)
{
	double	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
