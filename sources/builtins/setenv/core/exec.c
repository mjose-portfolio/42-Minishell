/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 05:32:12 by mjose             #+#    #+#             */
/*   Updated: 2018/10/10 17:29:39 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_and_exec_setenv(t_env *env, t_com *com)
{
	if (!com->arguments)
		print_env(env);
	else if (com->arguments > 2)
		put_err_setenv_arguments(&com->error);
	else if ((com->arguments == 2 || com->arguments == 1) &&
			(!ft_isalpha(com->tab_command[1][0])) &&
			com->tab_command[1][0] != '_')
		put_err_setenv_alpha(&com->error);
	else if (!check_var_name_is_alphanum(com) &&
			(com->arguments == 2 || com->arguments == 1))
		put_err_setenv_not_valid_name(&com->error);
	else if (com->arguments == 1)
		set_envvar_to_nothing(env, com);
	else
		set_envvar_to_something(env, com);
}
