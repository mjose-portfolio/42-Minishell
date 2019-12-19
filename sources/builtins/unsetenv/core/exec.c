/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 01:10:22 by mjose             #+#    #+#             */
/*   Updated: 2018/10/13 13:30:06 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_envvar_while_arguments(t_env *env, t_com *com)
{
	int		i;

	i = 1;
	while (com->tab_command[i])
	{
		if (com->tab_command[i][0] == '^' ||
				ft_strequ(com->tab_command[i], "*"))
		{
			env->is_removed = 2;
			rmv_environ(env);
			env->is_removed = 1;
		}
		else if (!env->is_removed)
			delete_var_from_env(env, com->tab_command[i]);
		i++;
	}
}

void	check_and_exec_unsetenv(t_env *env, t_com *com)
{
	if (!com->arguments)
		put_err_unsetenv_no_arguments(&com->error);
	else if (env->tab_env[0])
		unset_envvar_while_arguments(env, com);
	else
		return ;
}
