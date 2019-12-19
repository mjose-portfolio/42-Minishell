/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 02:20:20 by mjose             #+#    #+#             */
/*   Updated: 2018/10/23 05:38:09 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env_and_set_new_var(t_env *env, char *var, char *desc, int i)
{
	char	**new_env;

	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	if (!env->is_removed)
	{
		while (env->tab_env[i])
		{
			new_env[i] = ft_strdup(env->tab_env[i]);
			free(env->tab_env[i++]);
		}
	}
	new_env[i++] = ft_strjoin(var, desc);
	new_env[i] = NULL;
	if (!desc)
	{
		free(new_env[i - 1]);
		new_env[i - 1] = ft_strdup(var);
	}
	return (new_env);
}

void	set_new_env_var(t_env *env, char *var, char *desc)
{
	char	**new_env;
	int		i;

	i = 0;
	if (!env->is_removed)
	{
		while (env->tab_env[i])
			i++;
	}
	new_env = copy_env_and_set_new_var(env, var, desc, i);
	if (!env->is_removed)
		free(env->tab_env);
	env->tab_env = new_env;
	env->is_removed = 0;
}

void	set_pwd_to_curdir(t_env *env)
{
	char	*new_pwd;
	int		i;

	new_pwd = giveme_curpath();
	if ((search_index_tab_env(env, "PWD=") < 0))
	{
		set_new_env_var(env, "PWD=", new_pwd);
		i = search_index_tab_env(env, "PWD=");
	}
	free(env->path_current);
	env->path_current = new_pwd;
	env->is_removed = 0;
}

void	env_set_new_oldpwd(t_env *env)
{
	int		i;

	i = search_index_tab_env(env, "OLDPWD=");
	ft_strdel(&env->tab_env[i]);
	env->tab_env[i] = ft_strjoin("OLDPWD=", env->path_prev);
}

void	set_new_oldpwd_in_environment(t_env *env, char *new_oldpwd, char *to)
{
	int		i;

	i = 0;
	if ((i = search_index_tab_env(env, "PWD=")) >= 0)
	{
		ft_strdel(&env->tab_env[i]);
		if (!to || ft_strequ(to, ".") || ft_strequ(to, "..") ||
				ft_strequ(to, "-") || ft_strequ(to, "~"))
			env->tab_env[i] = ft_strjoin("PWD=", env->path_current);
		else if (to)
		{
			env->tab_env[i] = ft_strjoin("PWD=", to);
			ft_strdel(&env->path_current);
			env->path_current = ft_strdup(to);
		}
	}
	if (env_oldpwd_not_set(env))
	{
		free(new_oldpwd);
		return ;
	}
	else
		env_set_new_oldpwd(env);
	free(new_oldpwd);
}
