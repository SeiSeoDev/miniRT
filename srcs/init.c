/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:22:50 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/04 16:17:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_env		*init_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		exit_error(NULL, ERRNO_TO_STR);
	env->sceen = NULL;
	env->mlx = mlx_init();
	env->win = NULL;
	env->cam = NULL;
	env->nb_cam = 0;
	env->lgt = NULL;
	env->nb_lgt = 0;
	env->obj = NULL;
	env->nb_obj = 0;
	env->img = NULL;
	return (env);
}

t_cam		*init_camera(t_env *env)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		exit_error(env, ERRNO_TO_STR);
	cam->fov = 0;
	cam->next = NULL;
	return (cam);
}

void		append_cam(t_cam **cams, t_cam *new_cam)
{
	t_cam	*tmp;

	if (!cams || !new_cam)
		return ;
	tmp = *cams;
	if (*cams)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cam;
	}
	else
		*cams = new_cam;

}

t_lgt		*init_light(t_env *env)
{
	t_lgt	*lgt;

	lgt = (t_lgt *)malloc(sizeof(t_lgt));
	if (!lgt)
		exit_error(env, ERRNO_TO_STR);
	lgt->ratio = 0;
	lgt->next = NULL;
	return (lgt);
}

void		append_lgt(t_lgt **lgts, t_lgt *new_lgt)
{
	t_lgt	*tmp;

	if (!lgts || !new_lgt)
		return ;
	tmp = *lgts;
	if (*lgts)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lgt;
	}
	else
		*lgts = new_lgt;
}
