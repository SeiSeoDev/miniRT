/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:14:26 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/10 15:29:21 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_v3	v_init(double x, double y, double z)
{
	t_v3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_v3	v_add(t_v3 a, t_v3 b)
{
	t_v3 vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return (vec);
}

t_v3	v_sub(t_v3 a, t_v3 b)
{
	t_v3	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}

t_v3	v_cross(t_v3 a, t_v3 b)
{
	t_v3	vec;

	vec.x = a.y * b.z - a.z * b.y;
	vec.y = a.z * b.x - a.x * b.z;
	vec.z = a.x * b.y - a.y * b.x;
	return (vec);
}

t_v3	v_multi(double x, t_v3 a)
{
	t_v3	vec;

	vec.x = a.x * x;
	vec.y = a.y * x;
	vec.z = a.z * x;
	return (vec);
}
