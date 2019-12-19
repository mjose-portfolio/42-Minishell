/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:10:29 by mjose             #+#    #+#             */
/*   Updated: 2018/10/09 20:08:00 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_path_var_and_crt_exec_tab(char *exec, t_env *env)
{
	if (exec)
	{
		env->tab_exec = ft_strsplit(exec, ':');
		free(exec);
	}
	else
	{
		env->tab_exec = NULL;
		env->path_home = NULL;
		env->path_prev = NULL;
	}
}

void	check_arg_for_child(t_com *com, t_env *env)
{
	int		i;
	int		var;
	char	*new_val;

	i = 0;
	while (com->tab_command[i])
	{
		if (com->tab_command[i][0] == '$')
		{
			com->tab_command[i] = com->tab_command[i] + 1;
			if ((var = search_index_tab_env(env, com->tab_command[i])) > -1)
			{
				new_val = ft_strdup(ft_strchr(env->tab_env[var], '=') + 1);
				com->tab_command[i] = com->tab_command[i] - 1;
				ft_strdel(&com->tab_command[i]);
				com->tab_command[i] = new_val;
			}
			else
				com->tab_command[i] = com->tab_command[i] - 1;
		}
		i++;
	}
}
