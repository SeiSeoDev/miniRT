/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:30:18 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/05 16:22:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIRT_H_
# define _MINIRT_H_

#include "mlx.h"
#include "libft.h"
#include "libmath.h"
#include "miniRT_struct.h"
#include "miniRT_define.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

/*
** loop.c
*/

int			close_program(t_env *env);
int			key_handler(int keycode, t_env *env);
void		graphic_loop(t_env *env);

/*
** parsing.c
*/

void		pars_sceen(char *av, t_env *env);

/*
** init.c
*/

t_env		*init_env(void);
t_cam		*init_camera(t_env *env);
void		append_cam(t_cam **cams, t_cam *new_cam);
t_lgt		*init_light(t_env *env);
void		append_lgt(t_lgt **lgts, t_lgt *new_lgt);

/*
** print.c
*/

void		print_env(t_env *env);
void		print_cam(t_cam *cam);
void		print_lgt(t_lgt *lum);
void		print_cyl(t_cyl *cyl);
void		print_sqr(t_sqr *car);
void		print_tri(t_tri *tri);
void		print_pla(t_pla *pla);
void		print_sph(t_sph *sph);
void		print_ray(t_ray *ray);
void		print_obj(t_obj *obj);

/*
** obj.c
*/

t_obj		*init_object(t_env *env);
void		append_obj(t_obj **objs, t_obj *new_obj);
void		get_obj_color(t_obj *obj, t_ray *ray);
void		get_obj_normal(t_obj *obj, t_ray *ray);

/*
** Conv_nb.c
*/

double		str_to_double(t_env *env);
long long	str_to_long(t_env *env);
unsigned	str_to_unsigned(t_env *env);

/*
** mlx_img.c
*/

t_img		*init_img(t_env *env);
void		append_image(t_img **imgs, t_img *new);
void		delete_images(t_img **imgs, void *mlx_ptr);
void		circle_img_list(t_img *imgs, t_img *head);

/*
** render.c
*/

void		render(t_env *env);

/*
** tarce.c
*/

void		trace_ray(t_env *env, t_cam *cam);

/*
** trace_lgt.c
*/

t_v3		trace_ray_to_light(t_env *env, t_ray *ray);

/*
** trace_obj.c
*/

int			trace_sph(t_sph *sph, t_ray *ray);
int			trace_pla(t_pla *pla, t_ray *ray);
int			trace_sqr(t_sqr *sqr, t_ray *ray);
int			trace_cyl(t_cyl *cyl, t_ray *ray);
int			trace_tri(t_tri *tri, t_ray *ray);

/*
** hit.c
*/

t_obj		*trace_objs(t_obj *obj, t_ray *ray);
int			hit_obj(t_obj *obj, t_ray *ray, double *t);

/*
** intersect.c
*/

int			sphere_intersect(t_sph *sph, t_ray *ray, double *t);
int			cylinder_intersect(t_cyl *cyl, t_ray *ray, double *t);
int			plane_intersect(t_pla *pla, t_ray *ray, double *t);
int			square_intersect(t_sqr *sqr, t_ray *ray, double *t);
int			triangle_intersect(t_tri *tri, t_ray *ray, double *t);

/*
** inter_util.c
*/

int			solve_quadratic(t_v3 coef, double *x0, double *x1);
int			hit_plane(t_v3 pos, t_v3 dir, t_ray *ray, double *t);
int			check_edge(t_v3 to, t_v3 from, t_v3 hit, t_v3 normal);
int			solve_cylinder(t_cyl *cyl, t_ray *ray, t_v3 corf, double *t);

/*
** utils.c
*/

t_v3		rescale_vec(t_v3 vec, int min, int max);
char		*ft_strjoindelone(char *s1, char *s2);
int			rgb2color(int R, int G, int B);
double		MaxVal(int nb, ...);
void		swap(double *x, double *y);

/*
** look_at.c
*/

t_v3			canvas2view(t_env *env, t_cam *cam, int x, int y);
//double		**lookAt(double **cam2world, t_v3 dir, t_v3 pos);

/*
** ray.c
*/

void		reset_ray(t_ray *ray);
void		set_ray(t_ray *ray, t_v3 pos, t_v3 dir, double t);
void		init_ray(t_ray *ray);

/*
** get_color.c
*/

unsigned int		create_color(int trans, int red, int green, int blue);
unsigned int		get_trans(int color);
unsigned int		get_red(int color);
unsigned int		get_green(int color);
unsigned int		get_blue(int color);

/*
** get_scene.c
*/

void		get_camera(t_env *env);
void		get_light(t_env *env);
void		get_resolution(t_env *env);
void		get_ambient(t_env *env);

/*
** get_obj.c
*/

void		get_sphere(t_env *env);
void		get_plane(t_env *env);
void		get_square(t_env *env);
void		get_cylinder(t_env *env);
void		get_triangle(t_env *env);

/*
** get_normal.c
*/

t_v3		get_sph_normal(t_sph *sph, t_ray *ray);
t_v3		get_cyl_normal(t_cyl *cyl, t_ray *ray);
t_v3		get_tri_normal(t_tri *tri);


/*
** free.c
*/

void		free_env(t_env *env);

/*
** exit.c
*/

void		exit_error(t_env *env, t_errid id);
void		exit_sucess(t_env *env);

#endif
