/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:26:22 by tamigore          #+#    #+#             */
/*   Updated: 2021/02/01 16:09:55 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		get_resolution(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (*(env->sceen) == 'R')
		(env->sceen)++;
	env->res.x = str_to_unsigned(env);
	env->res.y = str_to_unsigned(env);
	mlx_get_screen_size(env->mlx, &x, &y);
	if (env->res.x > x)
		env->res.x = x;
	if (env->res.y > y)
		env->res.y = y;
}

void		get_ambient(t_env *env)
{
	if (*(env->sceen) == 'A')
		(env->sceen)++;
	env->amb.ratio = str_to_double(env);
	env->amb.color.x = str_to_unsigned(env);
	env->amb.color.y = str_to_unsigned(env);
	env->amb.color.z = str_to_unsigned(env);
}

void		get_camera(t_env *env)
{
	t_cam	*cam;

	if (*(env->sceen) == 'c')
		(env->sceen)++;
	cam = init_camera(env);
	cam->pos.x = str_to_double(env);
	cam->pos.y = str_to_double(env);
	cam->pos.z = str_to_double(env);
	cam->dir.x = str_to_double(env);
	cam->dir.y = str_to_double(env);
	cam->dir.z = str_to_double(env);
	cam->fov = str_to_unsigned(env);
	env->nb_cam++;
	append_cam(&(env->cam), cam);
}

void		get_light(t_env *env)
{
	t_lgt	*lgt;

	if (*(env->sceen) == 'c')
		(env->sceen)++;
	lgt = init_light(env);
	lgt->pos.x = str_to_double(env);
	lgt->pos.y = str_to_double(env);
	lgt->pos.z = str_to_double(env);
	lgt->ratio = str_to_double(env);
	lgt->color.x = str_to_unsigned(env);
	lgt->color.y = str_to_unsigned(env);
	lgt->color.z = str_to_unsigned(env);
	env->nb_lgt++;
	append_lgt(&(env->lgt), lgt);
}
