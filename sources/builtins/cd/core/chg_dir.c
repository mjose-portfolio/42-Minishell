/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chg_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 07:43:33 by mjose             #+#    #+#             */
/*   Updated: 2018/10/30 02:57:34 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chg_dir(char *new_dir, t_env *env)
{
	char	*tmp;

	tmp = ft_strdup(new_dir);
	free(env->path_prev);
	env->path_prev = giveme_curpath();
	if (!env->path_prev)
		env->path_prev = ft_strdup(env->path_current);
	chdir(tmp);
	free(env->path_current);
	env->path_current = giveme_curpath();
	free(tmp);
}

void	chg_dir_to_input(t_env *env, t_cd *cd)
{
	int		i;
	char	*new_oldpwd;
	char	*new_dir;

	i = 1;
	new_dir = NULL;
	env->err_env_home = 0;
	env->err_env_oldpwd = 0;
	new_dir = ft_strdup(cd->arg);
	aply_flag(cd, new_dir);
	check_prev_dir(cd, new_dir, env);
	if ((new_oldpwd = chg_dir_and_return_oldpwd(cd->arg, env)))
	{
		if (cd->no_opt || cd->opt_p)
			set_new_oldpwd_in_environment(env, new_oldpwd, NULL);
		else
			set_new_oldpwd_in_environment(env, new_oldpwd, cd->arg);
	}
	free(new_dir);
}

void	chg_dir_to_envvar(t_env *env, t_com *com, t_cd *cd)
{
	int		i;
	char	*new_oldpwd;
	char	*new_dir;

	i = 1;
	new_dir = NULL;
	env->err_env_home = 0;
	env->err_env_oldpwd = 0;
	new_dir = ft_strnew(ft_strlen(cd->arg));
	while (cd->arg[i])
	{
		new_dir[i - 1] = cd->arg[i];
		i++;
	}
	new_dir[i - 1] = '\0';
	if ((new_oldpwd = chg_dir_to_envvar_and_return_oldpwd(new_dir, env, com,
			cd)))
		set_new_oldpwd_in_environment(env, new_oldpwd, NULL);
}

void	chg_dir_to_oldpwd(t_env *env, t_com *com)
{
	char	*new_oldpwd;
	char	*dir_to_free;

	if (env_oldpwd_not_set(env))
	{
		put_err_cd_var_notset(com, "OLDPWD", env);
		env->err_env_home = 1;
		return ;
	}
	dir_to_free = ft_strdup(env->path_prev);
	if ((new_oldpwd = chg_dir_and_return_oldpwd(dir_to_free, env)))
	{
		set_new_oldpwd_in_environment(env, new_oldpwd, NULL);
		display_cur_dir(env);
	}
}

void	chg_dir_to_home(t_env *env, t_com *com, t_cd *cd)
{
	char	*new_oldpwd;
	char	*new_dir;

	if (env_home_not_set(env))
	{
		put_err_cd_var_notset(com, "HOME", env);
		env->err_env_home = 1;
		return ;
	}
	if (ft_strequ(cd->arg, "~"))
	{
		ft_strdel(&cd->arg);
		cd->arg = ft_strdup(env->path_home);
	}
	else
	{
		new_dir = ft_strdup(env->path_home);
		ft_strdel(&cd->arg);
		cd->arg = new_dir;
	}
	aply_flag(cd, cd->arg);
	if ((new_oldpwd = chg_dir_and_return_oldpwd(cd->arg, env)))
		set_new_oldpwd_in_environment(env, new_oldpwd, NULL);
}
