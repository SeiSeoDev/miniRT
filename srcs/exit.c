/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:04:48 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/04 16:14:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
** array of error identifiers associated to error messages
*/

static t_err	g_errors[] =
{
	{ AMB_DUP, "Invalid scene: Ambient light must be declared once.\n" },
	{ AMB_FMT, "Invalid scene: Ambient light badly formatted.\n" },
	{ CAM_FMT, "Invalid scene: Camera badly formatted.\n" },
	{ COLOR_FMT, "Invalid scene: Color badly formatted.\n" },
	{ COORD_FMT, "Invalid scene: Coordinates badly formatted.\n" },
	{ CYL_FMT, "Invalid scene: Cylinder badly formatted.\n" },
	{ FLOAT_FMT, "Invalid scene: Floating-point number badly formatted.\n" },
	{ FD_ERR, "Invalid scene file: Use the '.rt' extension.\n" },
	{ ID_ERR, "Invalid scene: Unknown identifier.\n" },
	{ LIGHT_FMT, "Invalid scene: Light badly formatted.\n" },
	{ NO_AMB, "No ambient light declared. Rendering stopped.\n" },
	{ NO_CAM, "No camera declared. Rendering stopped.\n" },
	{ NO_LIGHT, "No light declared. Rendering stopped.\n" },
	{ NO_OBJ, "No object declared. Rendering stopped.\n" },
	{ NO_RES, "No resolution declared. Rendering stopped.\n" },
	{ NUM_FMT, "Invalid scene: Number badly formatted.\n" },
	{ PLANE_FMT, "Invalid scene: Plane badly formatted.\n" },
	{ RES_DUP, "Invalid scene: Resolution must be declared once.\n" },
	{ RES_LOW, "Resolution too low: minimum is 300x300. Rendering stopped.\n" },
	{ SCENE_FMT, "Invalid scene: Scene badly formatted.\n" },
	{ SPHERE_FMT, "Invalid scene: Sphere badly formatted.\n" },
	{ SQUARE_FMT, "Invalid scene: Square badly formatted.\n" },
};

/*
** This function retrieves the appropriate error message using given error id
*/

static char	*get_error_msg(t_errid id)
{
	if (id != ERRNO_TO_STR)
		return (g_errors[id].msg);
	return ((char *)strerror(FAIL));
}

static void	print_err(t_errid id)
{
	char	*msg;

	msg = get_error_msg(id);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_sucess(t_env *env)
{
	free_env(env);
	ft_putstr("EXIT\n");
	exit(END);
}

void	exit_error(t_env *env, t_errid id)
{
	free_env(env);
	print_err(id);
}
