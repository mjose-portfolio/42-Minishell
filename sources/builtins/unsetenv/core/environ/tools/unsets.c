/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 06:57:02 by mjose             #+#    #+#             */
/*   Updated: 2018/10/30 06:00:54 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env_without_var(t_env *env, char *var, int i)
{
	char	**new_env;
	int		j;
	int		pos;

	j = 0;
	pos = search_index_tab_env(env, var);
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env->tab_env[i])
	{
		new_env[j] = ft_strdup(env->tab_env[i]);
		ft_strdel(&env->tab_env[i]);
		i++;
		if (i == pos)
		{
			ft_strdel(&env->tab_env[i]);
			i++;
		}
		j++;
	}
	free(env->tab_env);
	new_env[j] = NULL;
	return (new_env);
}

void	delete_var_from_env(t_env *env, char *var)
{
	int		i;
	char	*new_var;

	i = 0;
	new_var = ft_strjoin(var, "=");
	while (env->tab_env[i])
		i++;
	env->tab_env = copy_env_without_var(env, new_var, i);
	i = 0;
	if (ft_strequ(var, "HOME"))
		ft_strdel(&env->path_home);
	else if (ft_strequ(var, "PWD"))
		ft_strdel(&env->path_current);
	else if (ft_strequ(var, "OLDPWD"))
		ft_strdel(&env->path_prev);
	else if (ft_strequ(var, "PATH"))
		if (env->tab_exec)
		{
			while (env->tab_exec[i])
				ft_strdel(&env->tab_exec[i++]);
			free(env->tab_exec);
			env->tab_exec = NULL;
		}
	free(new_var);
}
