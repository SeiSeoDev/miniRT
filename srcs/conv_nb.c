/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:45:25 by tamigore          #+#    #+#             */
/*   Updated: 2022/03/04 14:47:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

unsigned			str_to_unsigned(t_env *env)
{
	unsigned long	nb;

	nb = 0;
	while (*(env->sceen) && (*(env->sceen) < '0' || *(env->sceen) > '9'))
		(env->sceen)++;
	while (*(env->sceen) && *(env->sceen) >= '0' && *(env->sceen) <= '9')
	{
		nb *= 10;
		nb += *(env->sceen) - '0';
		(env->sceen)++;
	}
	if (*(env->sceen) == ',')
		(env->sceen)++;
	return (nb);
}

long long			str_to_long(t_env *env)
{
	int				minus;
	long int		nb;

	minus = 1;
	while (*(env->sceen) && (*(env->sceen) < '0' || *(env->sceen) > '9'))
	{
		if (*(env->sceen) == '-')
			minus = -1;
		(env->sceen)++;
	}
	nb = str_to_unsigned(env);
	return (nb * minus);
}

double				str_to_double(t_env *env)
{
	int				minus;
	double			nb;
	long int		inte;

	nb = 0;
	minus = 1;
	while (*(env->sceen) && (*(env->sceen) < '0' || *(env->sceen) > '9'))
	{
		if (*(env->sceen) == '-')
			minus = -1;
		(env->sceen)++;
	}
	inte = str_to_unsigned(env);
	if (*(env->sceen) == '.')
	{
		(env->sceen)++;
		nb = (double)str_to_unsigned(env);
		while (nb >= 1)
			nb /= 10;
	}
	nb += (double)inte;
	return (nb * minus);
}
