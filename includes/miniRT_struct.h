/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:20:38 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/04 16:14:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIRT_STRUCT_H_
# define _MINIRT_STRUCT_H_

# include "libmath.h"

/*
** t_amb = struct for amb
**
** check = checks whether ambient light is declared and not duplicated
** ratio = ambient lighting ratio in range [0.0,1.0]
** color = R,G,B colors in range [0.0,1.0]
*/

typedef struct		s_amb
{
	int				check;
	t_v3			color;
	double			ratio;
}					t_amb;

/*
** t_res = struct for resolution
**
** check : checks if resolution is declared and not duplicated
** size_x: width of the image
** size_y: height of the image
*/

typedef struct		s_res
{
	int				check;
	int				x;
	int				y;
}					t_res;

/*
** t_cam = struct for camera
**
** pos = coordinates of the light point for {x, y, z} axis
** dir = 3D-normalized orientation vector in range [-1,1] for {x, y, z} axis
** fov = horizontal field of viewif (root1 > EPSILON && inside_cyl(cyl, ray, root1)) in degrees in range [0,180]
** cam2world = camera space to world space 3D matrix
** next: pointer to next camera
*/

typedef struct		s_cam
{
	t_v3			pos;
	t_v3			dir;
	int				fov;
//	double			**cam2world;
	struct s_cam	*next;
}					t_cam;

/*
** t_lum = struct for lights
**
** pos: x,y,z coordinates of the view point
** ratio: Light brightness ratio in range [0.0,1.0]
** color: color of the light in 3 vector R->G->B in range [0.0,1.0]
** next: Pointer to next light
*/

typedef struct		s_lgt
{
	t_v3			pos;
	double			ratio;
	t_v3			color;
	struct s_lgt	*next;
}					t_lgt;

/*
** t_pla = struct for planes
**
** pos = coordinates of the plane for {x,y,z} axis
** dir = 3D-normalized orientation vector in range [-1,1] for {x,y,z} axis
** color = color of the plane in 3 vector R->G->B in range [0.0,1.0]
*/

typedef struct		s_pla
{
	t_v3			pos;
	t_v3			dir;
	t_v3			color;
}					t_pla;

/*t_img		*init_img(t_env *env)

** t_sqr = struct for squares
**
** pos = coordinates of the square center for {x,y,z} axis
** dir = 3D-normalized orientation vector in range [-1,1] for {x,y,z} axis
** side = size of one side
** color = color of the square in 3 vector R->G->B in range [0.0,1.0]
*/

typedef struct		s_sqr
{
	t_v3			pos;
	t_v3			dir;
	double			side;
	t_v3			color;
}					t_sqr;

/*
** t_cyl = struct for cylinders
**
** pos = coordinates of the cylinder bottom for {x,y,z} axis
** dir = 3D-normalized orientation vector in range [-1,1] for {x,y,z} axis
** d = the cylinder diameter
** h = the cylinder height
** color = color of the cylinder in 3 vector R->G->B in range [0.0,1.0]
*/

typedef struct		s_cyl
{
	t_v3			pos;
	t_v3			dir;
	double			h;
	double			d;
	t_v3			color;
}					t_cyl;

/*
** t_tri = struct for triangles
**
** p1 = inital position in 3d space {x,y,z} of the first point
** p2 = inital position in 3d space {x,y,z} of the second point
** p3 = inital position in 3d space {x,y,z} of the third point
** color = color of the triangle in 3 vector R->G->B in range [0.0,1.0]
*/

typedef struct		s_tri
{
	t_v3			p1;
	t_v3			p2;
	t_v3			p3;
	t_v3			color;
}					t_tri;

/*
** t_sph = struct for spheres
**
** pos = inital position in 3d space {x,y,z}
** r = the sphere radius
** color = color of the sphere in 3 vector R->G->B in range [0.0,1.0]
*/

typedef struct		s_sph
{
	t_v3			pos;
	double			r;
	t_v3			color;
}					t_sph;

/*
** t_objid = enum for all object
*/

typedef enum		s_objid
{
	SPHERE,
	SQUARE,
	TRIANGLE,
	CYLINDER,
	PLANE
}					t_objid;

/*
** t_obj = struct for object
**
** id = type of object
** data = strcut of the object with all the data inside
** next = ptr for the next obj in the list
*/

typedef struct		s_obj
{
	t_objid			id;
	void			*data;
	struct s_obj	*next;
}					t_obj;

/*
** t_ray = struct for rays
**
** pos = inital position in 3d space {x, y, z}
** dir = direction of the ray in 3d space {x, y, z}
** t = distance along the direction from the initial point
** color = color of the ray in 3 vector R->G->B in range [0.0,1.0]
** hit = hit point
** normal at hit point
*/

typedef struct		s_ray
{
	t_v3			pos;
	t_v3			dir;
	double			t;
	t_v3			color;
	t_v3			hit;
	t_v3			normal;
}					t_ray;

/*
** Image
**
** size_x = width of the image
** size_y = height of the image
** img_ptr = pointer returned by the mlx_new_image() function
** pixels = pointer to image data returned by the mlx_get_data_addr() function
** The 3 following values are obtained using mlx_get_data_addr()
** bpp = bits per pixels
** size_line = the size (char) of a line
** endian = endian type (big : 1 / small : 0)
** next = pointer to next image
*/

typedef struct		s_img
{
	int				size_x;
	int				size_y;
	void			*ptr;
	char			*pixels;
	int				bpp;
	int				size_line;
	int				endian;
	struct s_img	*next;
}					t_img;

/*
** t_env = main struct
**
** sceen = contain the data from the sceen file
** mlx = mlx pointer returned by mlx_init()
** win = mlx pointer to the window screne
** res = resolution (width and height) of the window
** amb = ambient light parameters
** nb_cam = number of cameras in the scene
** cam = cameras in the scene
** nb_lgt = number of lights in the scene
** lgt = point lights in the scene
** nb_obj = number of objects in the scene
** obj = objects in the scene
** ray = ray trace throught the scene
** img = rendered images
*/

typedef struct		s_env
{
	char			*sceen;
	void			*mlx;
	void			*win;
	struct s_res	res;
	struct s_amb	amb;
	int				nb_cam;
	struct s_cam	*cam;
	int				nb_lgt;
	struct s_lgt	*lgt;
	int				nb_obj;
	struct s_obj	*obj;
	struct s_img	*img;
}					t_env;

/*
** t_errid = ID of the error
*/

typedef enum	e_errid
{
	ERRNO_TO_STR = -1,
	AMB_DUP,
	AMB_FMT,
	CAM_FMT,
	COLOR_FMT,
	COORD_FMT,
	CYL_FMT,
	FD_ERR,
	FLOAT_FMT,
	ID_ERR,
	LIGHT_FMT,
	NO_AMB,
	NO_CAM,
	NO_LIGHT,
	NO_OBJ,
	NO_RES,
	NUM_FMT,
	OPT_ERR,
	PLANE_FMT,
	RES_DUP,
	RES_LOW,
	SCENE_FMT,
	SPHERE_FMT,
	SQUARE_FMT,
}				t_errid;

/*
** t_err = error struct to exit
**
** id = ID of the error
** txt = error message
*/

typedef struct	s_err
{
	t_errid		id;
	char		*msg;
}				t_err;

/*
** t_pars_func = give the good function to the parser
*/

typedef	void	(*t_pars_func)(t_env *env);

/*
**
** t_pars = give the good function to the parser thanks to the id
*/

typedef struct	s_pars
{
	char		*id;
	int			id_len;
	t_pars_func	func;
}				t_pars;

#endif
