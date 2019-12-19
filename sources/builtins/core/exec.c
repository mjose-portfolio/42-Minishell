/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:29:56 by mjose             #+#    #+#             */
/*   Updated: 2018/10/15 18:47:40 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_com *com, t_env *env)
{
	int		i;
	char	*error;
	int		built;

	i = 0;
	built = check_type_cmd(com->tab_command[0]);
	if (built == 1)
		exec_env(env, com);
	else if (built == 2)
		check_and_chg_dir(env, com);
	else if (built == 3)
		check_and_exec_setenv(env, com);
	else if (built == 4)
		check_and_exec_unsetenv(env, com);
	else if (built == 5)
		check_and_exec_echo(env, com);
	else
	{
		error = ft_strjoin("minishell: command not found: ",
			com->tab_command[0]);
		ft_putendl_fd(error, 2);
		free(error);
	}
}
