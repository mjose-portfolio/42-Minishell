/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_without_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 00:07:05 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 00:15:02 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_var_whithout_envtmp(t_env_tmp *env_tmp)
{
	free(env_tmp->tab_env);
	env_tmp->tab_env = (char **)malloc(sizeof(char *) * 2);
	env_tmp->tab_env[0] = ft_strjoin(env_tmp->tmp_var, env_tmp->tmp_value);
	env_tmp->tab_env[1] = NULL;
	env_tmp->is_removed = 2;
	set_sysvar_envtmp(env_tmp);
}

void	set_sysvar_envtmp(t_env_tmp *env_tmp)
{
	if (ft_strequ(env_tmp->tmp_var, "PATH"))
	{
		crt_exectab_tmp(env_tmp);
		env_tmp->path_current = NULL;
		env_tmp->path_shell = NULL;
		env_tmp->is_removed = 0;
	}
	else if (ft_strequ(env_tmp->tmp_var, "HOME"))
	{
		env_tmp->path_home = ft_strdup(env_tmp->tmp_value);
		env_tmp->path_current = NULL;
		env_tmp->path_shell = NULL;
		env_tmp->is_removed = 0;
	}
	else if (ft_strequ(env_tmp->tmp_var, "OLDPWD"))
	{
		env_tmp->path_prev = ft_strdup(env_tmp->tmp_value);
		env_tmp->path_current = NULL;
		env_tmp->path_shell = NULL;
		env_tmp->is_removed = 0;
	}
}
