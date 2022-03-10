/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:20:45 by tamigore          #+#    #+#             */
/*   Updated: 2021/02/09 16:08:08 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double		**mat_init(void)
{
	double	**mat;
	int		i;

	mat = (double **)malloc(sizeof(double *) * 4);
	if (!mat)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		mat[i] = (double *)malloc(sizeof(double) * 4);
		if (!mat[i])
			return (NULL);
		mat[i++] = mat_fil(0, 0, 0, 0);
	}
	return (mat);
}

void		mat_free(double **mat)
{
	int		i;

	i = 0;
	while (i < 4)
		free(mat[i++]);
	free(mat);
}

double		*mat_fil(double a, double b, double c, double d)
{
	double	*tab;

	tab = (double *)malloc(sizeof(double) * 4);
	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	tab[3] = d;
	return (tab);
}

double		*mat_get_column(double **mat, int i)
{
	double	*col;

	col = NULL;
	if (i == 0)
		col = mat_fil(mat[0][0], mat[1][0], mat[2][0], mat[3][0]);
	else if (i == 1)
		col = mat_fil(mat[0][1], mat[1][1], mat[2][1], mat[3][1]);
	else if (i == 2)
		col = mat_fil(mat[0][2], mat[1][2], mat[2][2], mat[3][2]);
	else if (i == 3)
		col = mat_fil(mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
	return (col);
}

double		tab4_x_tab4(double	*a, double *b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3]);
}
