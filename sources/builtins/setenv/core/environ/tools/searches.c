/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:14:46 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 03:08:55 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	search_envvar_and_replace(t_env *env, char *envvar, char *new_value)
{
	int		i;
	char	*tmp;

	i = -1;
	set_sysvar(env, envvar, new_value);
	if (env->tab_env[0])
		i = search_index_tab_env(env, envvar);
	if (new_value)
		tmp = ft_strjoin(envvar, new_value);
	else
		tmp = ft_strdup(envvar);
	if (i != -1)
	{
		ft_strdel(&env->tab_env[i]);
		env->tab_env[i] = ft_strdup(tmp);
	}
	else
		set_new_env_var(env, envvar, new_value);
	free(tmp);
}
