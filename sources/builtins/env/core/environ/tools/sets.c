/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 05:29:09 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 00:13:52 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cp_evtmp_and_set_new_var(t_env_tmp *env, char *var, char *desc, int i)
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

void	set_new_envtmp_var(t_env_tmp *env, char *var, char *desc)
{
	char	**new_env;
	int		i;

	i = 0;
	if (!env->is_removed)
	{
		while (env->tab_env[i])
			i++;
	}
	new_env = cp_evtmp_and_set_new_var(env, var, desc, i);
	if (!env->is_removed)
		free(env->tab_env);
	env->tab_env = new_env;
	env->is_removed = 0;
}

void	fill_new_var(t_env_tmp *env_tmp, char *arg)
{
	int		i;
	int		j;

	i = 0;
	while (arg[i] != '=')
	{
		env_tmp->tmp_var[i] = arg[i];
		i++;
	}
	env_tmp->tmp_var[i] = '\0';
	j = i;
	i = 0;
	while (arg[j])
	{
		env_tmp->tmp_value[i] = arg[j];
		i++;
		j++;
	}
	env_tmp->tmp_value[i] = '\0';
}

void	set_envtmpvar(t_env_tmp *env_tmp, char *arg)
{
	int		i;
	int		j;

	i = 0;
	while (arg[i] != '=')
		i++;
	j = i + 1;
	while (arg[j])
		j++;
	env_tmp->tmp_var = (char *)malloc(sizeof(char) * (i + 1));
	env_tmp->tmp_value = (char *)malloc(sizeof(char) * (j + 1));
	fill_new_var(env_tmp, arg);
	if (env_tmp->tab_env)
		search_envtmpvar_and_replace(env_tmp, env_tmp->tmp_var,
			env_tmp->tmp_value);
	else
		set_var_whithout_envtmp(env_tmp);
	free(env_tmp->tmp_var);
	free(env_tmp->tmp_value);
}
