/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seiseo <seiseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:28:29 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/10 21:45:01 by seiseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
** usage : secure file
** ATTENTION |.rt|
*/
static int	usage(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '.')
		{
			if (!ft_strcmp(".rt", &str[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

static void			put_pixel_to_image(t_env *env, t_v3 color, int x, int y)
{
	int				i;

	i = (x * PIXEL_LEN + env->img->size_line * y);
	color = rescale_vec(color, 0, MAX_RGB);
	env->img->pixels[i + TRANS] = (unsigned int)0;
	env->img->pixels[i + RED] = (unsigned int)color.x;
	env->img->pixels[i + GREEN] = (unsigned int)color.y;
	env->img->pixels[i + BLUE] = (unsigned int)color.z;
}

// static void			shade(t_env *env, t_ray *ray)
// {
// 	t_obj			*hit_obj;

// 	hit_obj = trace_objs(env->obj, ray);
// 	if (hit_obj)
// 	{
// 		get_obj_color(hit_obj, ray);
// 		ray->hit = v_add(ray->pos, v_multi(ray->t, ray->dir));
// 		get_obj_normal(hit_obj, ray);
// 		ray->color = trace_ray_to_light(env, ray); // creat lights
// 		// if (ray->hit.x || ray->hit.z || ray->hit.y)
// 		// {
// 		// 	ray->color.x = 255;
// 		// 	ray->color.y = 255;
// 		// 	ray->color.z = 255;
// 		// }
// 	}
// }

int		inter(t_ray *ray, t_sph *sphere)
{
	double a = v_dot(ray->dir, ray->dir);
	double b = 2 * v_dot(ray->dir, v_sub(ray->pos, sphere->pos));
	double c = v_norm2(v_sub(ray->pos, sphere->pos)) - (sphere->r * sphere->r);
	double delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	//printf("DELTA : %f\n", v_dot(ray->dir, ray->dir));
	//printf("RAY : \n	pos : [%f, %f, %f]\n	dir : [%f, %f, %f]\n", ray->pos.x,ray->pos.y,ray->pos.z,ray->dir.x,ray->dir.y,ray->dir.z);
	//double t1 = (-b - sqrt(delta)) / (2 * a);
	double t2 = (-b + sqrt(delta)) / (2 * a);
	if (t2 > 0)
		return (1);
	// if (t1 > 0)
	// 	return (1);
	return (0);

}

void	img_calc(t_env *env)
{
	t_img *img;
	int x;
	int y;
	t_v3 color;
	t_ray ray;

	color.x = 250;
	color.y = 0;
	color.z = 0;

	x = 0;
	y = 0;
	init_ray(&ray);
	img = env->img;
	//printf("Image : %d / %d\n", img->size_x, img->size_y);
	//printf("CAM : \n	pos : [%f, %f, %f]\n	dir : [%f, %f, %f]\n", env->cam->pos.x,env->cam->pos.y,env->cam->pos.z,env->cam->dir.x,env->cam->dir.y,env->cam->dir.z);

	while (y < img->size_y)
	{
		while (x < img->size_x)
		{
			reset_ray(&ray);
			set_ray(&ray, env->cam->pos, v_init((double)x - (double)img->size_x / 2.0, (double)y - (double)img->size_y / 2.0, - (double)img->size_y / (double)(2 * tan((M_PI * env->cam->fov / 180) / 2))), INFINITY);
			ray.dir = v_norm(ray.dir);
		//	printf("RAY : \n	dir : [%f, %f, %f]\n", ray.dir.x,ray.dir.y,ray.dir.z);

			if (inter(&ray, (t_sph *)(env->obj->data)))
				put_pixel_to_image(env, color, x, y);
			else
				put_pixel_to_image(env, v_init(0,0,0), x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

/*
** main : check | pars & initialize | compute ray | graphic interface
*/
int			main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2 || !av || !usage(av[1])) // first check
	{
			ft_putstr_fd("Error: Usage: minirt: ./miniRT <scene.rt>\n", 2);
			exit(0);
	}
	printf("arg : %s\n", av[1]);
	env = init_env(); // second check && init
	pars_sceen(av[1], env); // parsing
	env->img = init_img(env);
	img_calc(env);
	graphic_loop(env);
	return (END);
}
