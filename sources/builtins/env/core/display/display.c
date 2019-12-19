/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 05:43:32 by mjose             #+#    #+#             */
/*   Updated: 2018/10/30 02:30:57 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_tmp(t_env_tmp *env)
{
	int		i;

	if (env->tab_env)
	{
		i = 0;
		while (env->tab_env[i])
			ft_putendl(env->tab_env[i++]);
	}
}
