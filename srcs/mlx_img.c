/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:33:11 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/10 11:03:27 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_img		*init_img(t_env *env)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		exit_error(env, ERRNO_TO_STR);
	img->size_x = env->res.x;
	img->size_y = env->res.y;
	img->bpp = 32;
	img->size_line = (img->bpp / 8) * img->size_x;
	img->endian = 0;
	img->ptr = mlx_new_image(env->mlx, img->size_x, img->size_y);
	img->pixels = mlx_get_data_addr(img->ptr, &(img->bpp),
				&(img->size_line), &(img->endian));
	img->next = NULL;
	return (img);
}

void		append_image(t_img **imgs, t_img *new)
{
	t_img	*tmp;

	if (!imgs || !new)
		return ;
	if (*imgs)
	{
		tmp = *imgs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*imgs = new;
}

void		delete_images(t_img **imgs, void *mlx_ptr)
{
	t_img	*cursor;
	t_img	*head;

	if (!imgs)
		return ;
	if (*imgs)
	{
		head = *imgs;
		while (*imgs)
		{
			cursor = *imgs;
			*imgs = (*imgs)->next;
			mlx_destroy_image(mlx_ptr, cursor);
			free(cursor);
			if (*imgs == head)
				*imgs = NULL;
		}
	}
}

void		circle_img_list(t_img *imgs, t_img *head)
{
	while (imgs->next)
		imgs = imgs->next;
	imgs->next = head;
	imgs = imgs->next;
}
