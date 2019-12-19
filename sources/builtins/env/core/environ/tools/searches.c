/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 05:34:18 by mjose             #+#    #+#             */
/*   Updated: 2018/10/08 18:12:47 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_index_tab_envtmp(t_env_tmp *env, char *value)
{
	int		i;
	char	*new_value;

	i = 0;
	if (env->is_removed)
		return (-1);
	new_value = ft_strjoin(value, "=");
	while (!ft_strnequ(env->tab_env[i], new_value, ft_strlen(new_value)))
		if (!env->tab_env[++i])
			break ;
	free(new_value);
	if (!env->tab_env[i])
		return (-1);
	return (i);
}

void	search_envtmpvar_and_replace(t_env_tmp *env, char *var, char *value)
{
	int		i;
	char	*tmp;

	i = search_index_tab_envtmp(env, var);
	if (value)
		tmp = ft_strjoin(var, value);
	else
		tmp = ft_strdup(var);
	if (i != -1)
	{
		ft_strdel(&env->tab_env[i]);
		env->tab_env[i] = ft_strdup(tmp);
	}
	else
		set_new_envtmp_var(env, var, value);
	free(tmp);
	if (ft_strequ(var, "PATH") || ft_strequ(var, "HOME") ||
		ft_strequ(var, "OLDPWD"))
	{
		rmv_exectab_tmp(env);
		crt_exectab_tmp(env);
	}
}
