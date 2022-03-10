/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:14:45 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/10 15:30:09 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include <stdio.h>
t_v3	v_prod(t_v3 a, t_v3 b)
{
	t_v3 vec;

	vec.x = a.x * b.x;
	vec.y = a.y * b.y;
	vec.z = a.z * b.z;
	return (vec);
}

int		v_comp(t_v3 u, t_v3 v)
{
	if (u.x == v.x && u.y == v.y && u.z == v.z)
		return (1);
	else
		return (0);
}

double	v_len(t_v3 v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

t_v3	v_norm(t_v3 vec)
{
	vec.x = vec.x / v_len(vec);
	vec.y = vec.y / v_len(vec);
	vec.z = vec.z / v_len(vec);
	//printf("vec : [%f, %f, %f]\n", vec.x, vec.y, vec.z);
	return (vec);
}

double	v_dot(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	v_norm2(t_v3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}