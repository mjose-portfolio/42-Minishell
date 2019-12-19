/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_tmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 05:53:50 by mjose             #+#    #+#             */
/*   Updated: 2018/10/16 23:24:35 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rmv_exectab_tmp(t_env_tmp *env)
{
	int		i;

	i = 0;
	if (env->tab_exec)
	{
		while (env->tab_exec[i])
			ft_strdel(&env->tab_exec[i++]);
		free(env->tab_exec);
	}
	if (env->path_home)
		free(env->path_home);
	if (env->path_prev)
		free(env->path_prev);
}

void	rmv_environ_tmp(t_env_tmp *env)
{
	int		i;

	i = 0;
	if (env->is_removed == 2)
	{
		while (env->tab_env[i])
			ft_strdel(&env->tab_env[i++]);
		free(env->tab_env);
	}
	if (env->is_removed == 1 || env->is_removed == 0)
	{
		if (env->is_removed == 0)
		{
			while (env->tab_env[i])
				ft_strdel(&env->tab_env[i++]);
			free(env->tab_env);
		}
		if (env->path_shell)
			ft_strdel(&env->path_shell);
		if (env->path_current)
			free(env->path_current);
		rmv_exectab_tmp(env);
	}
}

void	crt_exectab_tmp(t_env_tmp *env)
{
	int		i;
	char	*exec;

	i = 0;
	exec = NULL;
	env->path_home = NULL;
	env->path_prev = NULL;
	if (env->tab_env)
	{
		while (env->tab_env[i])
		{
			if (ft_strnequ(env->tab_env[i], "PATH=", ft_strlen("PATH=")))
				exec = ft_strdup(ft_strchr(env->tab_env[i], '=') + 1);
			else if (ft_strnequ(env->tab_env[i], "HOME=", ft_strlen("HOME=")))
				env->path_home = ft_strdup(ft_strchr(env->tab_env[i], '=') + 1);
			else if (ft_strnequ(env->tab_env[i], "OLDPWD=",
				ft_strlen("OLDPWD=")))
				env->path_prev = ft_strdup(ft_strchr(env->tab_env[i], '=') + 1);
			i++;
		}
		check_path_vartmp_and_crt_tmp_exec_tab(exec, env);
	}
}

void	setenv_tmp_shell(t_env *env, t_env_tmp *env_tmp)
{
	if (env->path_current)
		env_tmp->path_current = ft_strdup(env->path_current);
	else
		env_tmp->path_current = NULL;
	if (env->path_shell)
		env_tmp->path_shell = ft_strdup(env->path_shell);
	else
		env_tmp->path_shell = NULL;
}

void	crt_environ_tmp(t_env *env, t_env_tmp *env_tmp, char *first_arg)
{
	if (!first_arg || first_arg[0] != '-')
	{
		check_env_and_and_cpy_to_tmp(env, env_tmp);
		setenv_tmp_shell(env, env_tmp);
		crt_exectab_tmp(env_tmp);
	}
	else if (first_arg[0] == '-')
		if (first_arg[1] && first_arg[1] == 'i')
		{
			env_tmp->tab_env = NULL;
			env_tmp->tab_exec = NULL;
		}
}
