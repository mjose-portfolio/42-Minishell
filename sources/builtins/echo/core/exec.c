/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 05:17:34 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 04:13:23 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_echo(t_env *env, t_com *com)
{
	int		i;

	i = 1;
	while (com->tab_command[i])
	{
		if (com->tab_command[i])
		{
			if (com->tab_command[i][0] == '$')
				print_varenv_echo(env, com->tab_command[i],
					com->tab_command[i]);
			else if (ft_strequ(com->tab_command[i], "~") ||
					com->tab_command[i][0] == '~')
				print_varenv_echo(env, "$HOME", com->tab_command[i]);
			else
				ft_putstr(com->tab_command[i]);
			i++;
			if (!com->tab_command[i])
				ft_putchar('\n');
			else
				ft_putchar(' ');
		}
		else
			ft_putchar('\n');
	}
}

void	check_and_exec_echo(t_env *env, t_com *com)
{
	if (!com->arguments)
		ft_putchar('\n');
	else
		exec_echo(env, com);
}
