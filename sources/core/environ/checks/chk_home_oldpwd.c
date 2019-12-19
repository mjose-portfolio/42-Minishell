/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_home_oldpwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:10:34 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 03:31:13 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_oldpwd_not_set(t_env *env)
{
	int		i;
	char	*to_free;

	i = search_index_tab_env(env, "OLDPWD=");
	if (i < 0)
	{
		env->err_env_oldpwd = 1;
		return (1);
	}
	else
	{
		to_free = ft_strdup(ft_strrchr(env->tab_env[i], '='));
		if (!to_free[1])
		{
			free(to_free);
			env->err_env_oldpwd = 1;
			return (1);
		}
		free(to_free);
	}
	env->err_env_oldpwd = 0;
	return (0);
}

int		env_home_not_set(t_env *env)
{
	int		i;
	char	*to_free;

	i = search_index_tab_env(env, "HOME=");
	if (i < 0)
	{
		env->err_env_home = 1;
		return (1);
	}
	else
	{
		to_free = ft_strdup(ft_strrchr(env->tab_env[i], '='));
		if (!to_free[1])
		{
			free(to_free);
			env->err_env_home = 1;
			return (1);
		}
		free(to_free);
	}
	env->err_env_home = 0;
	return (0);
}
