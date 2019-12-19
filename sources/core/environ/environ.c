/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:46:04 by mjose             #+#    #+#             */
/*   Updated: 2018/10/22 07:36:32 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rmv_exectab(t_env *env)
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

void	rmv_environ(t_env *env)
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
		if (env->is_removed == 0 && env->tab_env)
		{
			while (env->tab_env[i])
				ft_strdel(&env->tab_env[i++]);
			free(env->tab_env);
		}
		ft_strdel(&env->path_shell);
		free(env->path_current);
		rmv_exectab(env);
	}
}

void	crt_exectab(t_env *env)
{
	char	*exec;
	int		i;

	i = 0;
	exec = NULL;
	env->err_env_home = 0;
	env->err_env_oldpwd = 0;
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
		check_path_var_and_crt_exec_tab(exec, env);
	}
}

void	setenv_shell(t_env *env)
{
	int			i;
	char		*cur_pathtmp;
	char		*cur_path;

	i = 0;
	env->is_removed = 0;
	cur_pathtmp = giveme_curpath();
	env->path_current = ft_strdup(cur_pathtmp);
	cur_path = ft_strjoin(cur_pathtmp, "/");
	free(cur_pathtmp);
	env->path_shell = ft_strjoin(cur_path, "minishell");
	free(cur_path);
	if (env->tab_env)
	{
		while (env->tab_env[i])
		{
			if (ft_strnequ(env->tab_env[i], "SHELL=", ft_strlen("SHELL=")))
			{
				ft_strdel(&env->tab_env[i]);
				env->tab_env[i] = ft_strjoin("SHELL=", env->path_shell);
			}
			i++;
		}
	}
}

void	crt_environ(t_env *env)
{
	extern char **environ;
	int			i;

	i = 0;
	env->path_current = NULL;
	env->path_prev = NULL;
	env->path_home = NULL;
	if (environ)
	{
		while (environ[i])
			i++;
		env->tab_env = (char **)malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (environ[i])
		{
			env->tab_env[i] = ft_strdup(environ[i]);
			i++;
		}
		env->tab_env[i] = NULL;
	}
	setenv_shell(env);
	crt_exectab(env);
}
