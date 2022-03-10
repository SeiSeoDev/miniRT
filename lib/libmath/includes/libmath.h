/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:31:48 by tamigore          #+#    #+#             */
/*   Updated: 2021/02/04 19:22:04 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define UNIT 1.0
# define ZERO 0.0
# define REV -1.0
# define HALF_ANGLE 90
# define FLAT_ANGLE 180
# define FULL_ANGLE 360

/*
** v3 = vector 3d
** v3 = {a, b, c};
*/

typedef struct	s_v3
{
	double		x;
	double		y;
	double		z;
}				t_v3;

/*
** m4 = matrice 4x4
**
** \ w x y z
** a 0 0 0 0
** b 0 0 0 0
** c 0 0 0 0
** d 0 0 0 0
*/

/*
** VECTOR.C vector basics
*/

t_v3			v_init(double x, double y, double z);
t_v3			v_add(t_v3 a, t_v3 b);
t_v3			v_sub(t_v3 a, t_v3 b);
t_v3			v_cross(t_v3 a, t_v3 b);
t_v3			v_multi(double x, t_v3 a);

/*
** VECTOR_2.C vector operation
*/

t_v3			v_prod(t_v3 a, t_v3 b);
double			v_len(t_v3 v);
t_v3			v_norm(t_v3 vec);
double			v_dot(t_v3 a, t_v3 b);
int				v_comp(t_v3 u, t_v3 v);

/*
** ANGLES.C trigo basics
*/

double			rad(int deg);
double			tan(double x);
double			deg(double rad);
double			v_cos(t_v3 a, t_v3 b);

/*
** MATRIX.C matrix init and fill
*/

double			**mat_init(void);
void			mat_free(double **mat);
double			*mat_fil(double a, double b, double c, double d);
double			*mat_get_column(double **mat, int i);
double			tab4_x_tab4(double *a, double *b);

/*
** MATRIX_OP.C operation matrix
*/

void			mat4_x_mat4(double **a, double **b, double **mat);
t_v3			vec3_x_mat4(t_v3 vec, double **m);
int				mat_invers(double **m, double **invert);

#endif
