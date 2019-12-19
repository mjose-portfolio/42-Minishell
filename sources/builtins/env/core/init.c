/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:54:24 by mjose             #+#    #+#             */
/*   Updated: 2018/10/16 23:59:29 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_envtmp(t_env_tmp *env)
{
	env->path_current = NULL;
	env->path_home = NULL;
	env->path_prev = NULL;
	env->path_shell = NULL;
	env->tab_env = NULL;
	env->tab_exec = NULL;
}
