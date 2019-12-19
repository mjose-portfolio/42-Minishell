/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:49:18 by mjose             #+#    #+#             */
/*   Updated: 2018/10/09 22:57:56 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_path_vartmp_and_crt_tmp_exec_tab(char *exec, t_env_tmp *env)
{
	if (exec)
	{
		env->tab_exec = ft_strsplit(exec, ':');
		free(exec);
	}
	else
		env->tab_exec = NULL;
}

void	check_env_and_and_cpy_to_tmp(t_env *env, t_env_tmp *env_tmp)
{
	int			i;

	i = 0;
	if (env->tab_env)
	{
		env_tmp->err_env_home = env->err_env_home;
		env_tmp->err_env_oldpwd = env->err_env_oldpwd;
		env_tmp->is_removed = env->err_env_oldpwd;
		while (env->tab_env[i])
			i++;
		env_tmp->tab_env = (char **)malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (env->tab_env[i])
		{
			env_tmp->tab_env[i] = ft_strdup(env->tab_env[i]);
			i++;
		}
		env_tmp->tab_env[i] = NULL;
	}
	else
		env_tmp->tab_env = NULL;
}

void	check_arg_for_envchild(int fst_arg, int i, t_env_tmp *ev_tmp, t_com *cm)
{
	int		var;

	if (cm->tab_command[fst_arg][0] == '$')
	{
		cm->tab_command[fst_arg] = cm->tab_command[fst_arg] + 1;
		if ((var = search_index_tab_envtmp(ev_tmp,
				cm->tab_command[fst_arg])) > -1)
			ev_tmp->env_com.tab_command[i] =
				ft_strdup(ft_strchr(ev_tmp->tab_env[var], '=') + 1);
		cm->tab_command[fst_arg] = cm->tab_command[fst_arg] - 1;
	}
	else
		ev_tmp->env_com.tab_command[i] =
			ft_strdup(cm->tab_command[fst_arg]);
}

int		is_for_chg_env_tmp(char *arg)
{
	int		i;

	i = 0;
	if (arg)
		while (arg[i])
		{
			if (arg[i] == '=')
				return (1);
			i++;
		}
	return (0);
}
