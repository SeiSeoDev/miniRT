/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:36:40 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/04 17:57:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
** This array give the good function to the good id
*/

static t_pars	g_parsers[] =
{
	{ SPH_ID, ID_OBJ_LEN, &get_sphere },
	{ PLA_ID, ID_OBJ_LEN, &get_plane },
	{ SQR_ID, ID_OBJ_LEN, &get_square },
	{ CYL_ID, ID_OBJ_LEN, &get_cylinder },
	{ TRI_ID, ID_OBJ_LEN, &get_triangle },
	{ RES_ID, ID_LEN, &get_resolution },
	{ AMB_ID, ID_LEN, &get_ambient },
	{ CAM_ID, ID_LEN, &get_camera },
	{ LGT_ID, ID_LEN, &get_light }
};

/*
** This function calls the appropriate function to parse a line
*/

static void		fill_env_sceen(t_env *env)
{
	int			j;

	j = 0;
	while (j < 9)
	{
		if (!ft_strncmp(g_parsers[j].id, env->sceen, g_parsers[j].id_len))
		{
			(*g_parsers[j].func)(env);
			return ;
		}
		j++;
	}
	exit_error(env, ID_ERR);
}

/*
** This function compar all scene ID
*/

static int		comp_all(char *txt)
{
	int			i;

	i = 0;
	while (i < 9)
	{
		if (!ft_strncmp(g_parsers[i].id, txt, g_parsers[i].id_len))
			return (1);
		i++;
	}
	return (0);
}

/*
** This fonction read all the scene and return it as a string
*/

static char		*read_sceen(t_env *env, char *file_path)
{
	char		*result;
	char		buffer[BUFFER_SIZE + 1];
	int			fd;
	int			bytes_read;

	result = NULL;
	fd = open(file_path, O_RDONLY);
	if (!fd)
		exit_error(env, ERRNO_TO_STR);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		result = ft_strjoindelone(result, buffer);
		if (!result)
			exit_error(env, ERRNO_TO_STR);
	}
	close(fd);
	return (result);
}

/*
** This fonction pars the scene to the structures and check for errors
*/

void			pars_sceen(char *av, t_env *env)
{
	char		*head;

	env->sceen = read_sceen(env, av);
	if (!env->sceen)
		exit_error(env, ERRNO_TO_STR);
	head = env->sceen;
	while (*(env->sceen))
	{
		if (*(env->sceen) == '\n')
			(env->sceen)++;
		else if (comp_all(env->sceen))
			fill_env_sceen(env);
		else
			exit_error(env, SCENE_FMT);
	}
	env->sceen = head;
//	check_scene(env);
//	check_max_display(env);
	free(head);
}
