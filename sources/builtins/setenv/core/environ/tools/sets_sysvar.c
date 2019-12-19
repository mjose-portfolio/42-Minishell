/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_sysvar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 02:45:19 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 03:08:39 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_sysvar_path(t_env *env, char *new_value)
{
	int		i;

	i = 0;
	if (env->tab_exec)
	{
		while (env->tab_exec[i])
			ft_strdel(&env->tab_exec[i++]);
		free(env->tab_exec);
	}
	if (new_value)
		create_new_path_var(new_value, env);
	else
		env->tab_exec = NULL;
}

void	set_sysvar_oldpwd(t_env *env, char *new_value)
{
	if (env->path_prev)
		free(env->path_prev);
	if (new_value)
		env->path_prev = ft_strdup(new_value);
	else
		env->path_prev = NULL;
}

void	set_sysvar_home(t_env *env, char *new_value)
{
	if (env->path_home)
		free(env->path_home);
	if (new_value)
		env->path_home = ft_strdup(new_value);
	else
		env->path_home = NULL;
}

void	set_sysvar(t_env *env, char *envvar, char *new_value)
{
	int	i;

	i = 0;
	if (ft_strequ(envvar, "HOME="))
		set_sysvar_home(env, new_value);
	else if (ft_strequ(envvar, "OLDPWD="))
		set_sysvar_oldpwd(env, new_value);
	else if (ft_strequ(envvar, "PATH="))
		set_sysvar_path(env, new_value);
}
