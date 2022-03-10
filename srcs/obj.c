/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <taigore@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:32:20 by tamigore          #+#    #+#             */
/*   Updated: 2021/02/03 15:15:20 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj		*init_object(t_env *env)
{
	t_obj	*obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
		exit_error(env, ERRNO_TO_STR);
	obj->data = NULL;
	obj->next = NULL;
	return (obj);
}

void		append_obj(t_obj **objs, t_obj *new_obj)
{
	t_obj	*tmp;

	if (!objs || !new_obj)
		return ;
	tmp = *objs;
	if (*objs)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_obj;
	}
	else
		*objs = new_obj;
}

void	get_obj_color(t_obj *obj, t_ray *ray)
{
	if (obj->id == SPHERE)
		ray->color = ((t_sph *)(obj->data))->color;
	else if (obj->id == PLANE)
		ray->color = ((t_pla *)(obj->data))->color;
	else if (obj->id == SQUARE)
		ray->color = ((t_sqr *)(obj->data))->color;
	else if (obj->id == CYLINDER)
		ray->color = ((t_cyl *)(obj->data))->color;
	else if (obj->id == TRIANGLE)
		ray->color = ((t_tri *)(obj->data))->color;
}

void	get_obj_normal(t_obj *obj, t_ray *ray)
{
	if (obj->id == SPHERE)
		ray->normal = get_sph_normal((t_sph *)(obj->data), ray);
	else if (obj->id == PLANE)
		ray->normal = ((t_pla *)(obj->data))->dir;
	else if (obj->id == SQUARE)
		ray->normal = ((t_sqr *)(obj->data))->dir;
	else if (obj->id == CYLINDER)
		ray->normal = get_cyl_normal((t_cyl *)(obj->data), ray);
	else if (obj->id == TRIANGLE)
		ray->normal = get_tri_normal((t_tri *)(obj->data));
	if (v_dot(ray->dir, ray->normal) > 0)
		v_multi(-1, ray->normal);
}
