/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:28:44 by tamigore          #+#    #+#             */
/*   Updated: 2021/02/01 16:11:40 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		get_sphere(t_env *env)
{
	t_obj	*obj;

	if (!ft_strncmp(env->sceen, SPH_ID, ID_OBJ_LEN))
		(env->sceen) += ID_OBJ_LEN;
	obj = init_object(env);
	obj->id = SPHERE;
	obj->data = malloc(sizeof(t_sph));
	if (!obj->data)
	{
		free(obj);
		exit_error(env, ERRNO_TO_STR);
	}
	((t_sph *)(obj->data))->pos.x = str_to_double(env);
	((t_sph *)(obj->data))->pos.y = str_to_double(env);
	((t_sph *)(obj->data))->pos.z = str_to_double(env);
	((t_sph *)(obj->data))->r = str_to_double(env);
	((t_sph *)(obj->data))->color.x = str_to_unsigned(env);
	((t_sph *)(obj->data))->color.y = str_to_unsigned(env);
	((t_sph *)(obj->data))->color.z = str_to_unsigned(env);
	env->nb_obj++;
	append_obj(&(env->obj), obj);
}

void		get_plane(t_env *env)
{
	t_obj	*obj;

	if (!ft_strncmp(env->sceen, PLA_ID, ID_OBJ_LEN))
		(env->sceen) += ID_OBJ_LEN;
	obj = init_object(env);
	obj->id = PLANE;
	obj->data = malloc(sizeof(t_pla));
	if (!obj->data)
	{
		free(obj);
		exit_error(env, ERRNO_TO_STR);
	}
	((t_pla *)(obj->data))->pos.x = str_to_double(env);
	((t_pla *)(obj->data))->pos.y = str_to_double(env);
	((t_pla *)(obj->data))->pos.z = str_to_double(env);
	((t_pla *)(obj->data))->dir.x = str_to_double(env);
	((t_pla *)(obj->data))->dir.y = str_to_double(env);
	((t_pla *)(obj->data))->dir.z = str_to_double(env);
	((t_pla *)(obj->data))->color.x = str_to_unsigned(env);
	((t_pla *)(obj->data))->color.y = str_to_unsigned(env);
	((t_pla *)(obj->data))->color.z = str_to_unsigned(env);
	env->nb_obj++;
	append_obj(&(env->obj), obj);
}

void		get_square(t_env *env)
{
	t_obj	*obj;

	if (!ft_strncmp(env->sceen, SQR_ID, ID_OBJ_LEN))
		(env->sceen) += ID_OBJ_LEN;
	obj = init_object(env);
	obj->id = SQUARE;
	obj->data = malloc(sizeof(t_sqr));
	if (!obj->data)
	{
		free(obj);
		exit_error(env, ERRNO_TO_STR);
	}
	((t_sqr *)(obj->data))->pos.x = str_to_double(env);
	((t_sqr *)(obj->data))->pos.y = str_to_double(env);
	((t_sqr *)(obj->data))->pos.z = str_to_double(env);
	((t_sqr *)(obj->data))->dir.x = str_to_double(env);
	((t_sqr *)(obj->data))->dir.y = str_to_double(env);
	((t_sqr *)(obj->data))->dir.z = str_to_double(env);
	((t_sqr *)(obj->data))->side = str_to_double(env);
	((t_sqr *)(obj->data))->color.x = str_to_unsigned(env);
	((t_sqr *)(obj->data))->color.y = str_to_unsigned(env);
	((t_sqr *)(obj->data))->color.z = str_to_unsigned(env);
	env->nb_obj++;
	append_obj(&(env->obj), obj);
}

void		get_cylinder(t_env *env)
{
	t_obj	*obj;

	if (!ft_strncmp(env->sceen, CYL_ID, ID_OBJ_LEN))
		(env->sceen) += ID_OBJ_LEN;
	obj = init_object(env);
	obj->id = CYLINDER;
	obj->data = malloc(sizeof(t_cyl));
	if (!obj->data)
	{
		free(obj);
		exit_error(env, ERRNO_TO_STR);
	}
	((t_cyl *)(obj->data))->pos.x = str_to_double(env);
	((t_cyl *)(obj->data))->pos.y = str_to_double(env);
	((t_cyl *)(obj->data))->pos.z = str_to_double(env);
	((t_sqr *)(obj->data))->dir.x = str_to_double(env);
	((t_cyl *)(obj->data))->dir.y = str_to_double(env);
	((t_cyl *)(obj->data))->dir.z = str_to_double(env);
	((t_cyl *)(obj->data))->d = str_to_double(env);
	((t_cyl *)(obj->data))->h = str_to_double(env);
	((t_cyl *)(obj->data))->color.x = str_to_unsigned(env);
	((t_cyl *)(obj->data))->color.y = str_to_unsigned(env);
	((t_cyl *)(obj->data))->color.z = str_to_unsigned(env);
	env->nb_obj++;
	append_obj(&(env->obj), obj);
}

void		get_triangle(t_env *env)
{
	t_obj	*obj;

	if (!ft_strncmp(env->sceen, CYL_ID, ID_OBJ_LEN))
		(env->sceen) += ID_OBJ_LEN;
	obj = init_object(env);
	obj->id = TRIANGLE;
	obj->data = malloc(sizeof(t_tri));
	if (!obj->data)
	{
		free(obj);
		exit_error(env, ERRNO_TO_STR);
	}
	((t_tri *)(obj->data))->p1.x = str_to_double(env);
	((t_tri *)(obj->data))->p1.y = str_to_double(env);
	((t_tri *)(obj->data))->p1.z = str_to_double(env);
	((t_tri *)(obj->data))->p2.x = str_to_double(env);
	((t_tri *)(obj->data))->p2.y = str_to_double(env);
	((t_tri *)(obj->data))->p2.z = str_to_double(env);
	((t_tri *)(obj->data))->p3.x = str_to_double(env);
	((t_tri *)(obj->data))->p3.y = str_to_double(env);
	((t_tri *)(obj->data))->p3.z = str_to_double(env);
	((t_tri *)(obj->data))->color.x = str_to_unsigned(env);
	((t_tri *)(obj->data))->color.y = str_to_unsigned(env);
	((t_tri *)(obj->data))->color.z = str_to_unsigned(env);
	env->nb_obj++;
	append_obj(&(env->obj), obj);
}
