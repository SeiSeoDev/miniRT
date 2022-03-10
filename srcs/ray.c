/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:26:22 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/10 14:15:49 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		reset_ray(t_ray *ray)
{
	ray->t = INFINITY;
	ray->color = v_init(0, 0, 0);
	ray->hit = v_init(0, 0, 0);
	ray->normal = v_init(0, 0, 0);
}

void		set_ray(t_ray *ray, t_v3 pos, t_v3 dir, double t)
{
	ray->pos = pos;
	ray->dir = dir;
	ray->t = t;
}

void		init_ray(t_ray *ray)
{
	set_ray(ray, v_init(0, 0, 0), v_init(0, 0, 0), 0);
	reset_ray(ray);
}
