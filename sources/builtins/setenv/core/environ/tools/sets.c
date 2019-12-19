/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 01:47:29 by mjose             #+#    #+#             */
/*   Updated: 2018/10/10 18:19:01 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_envvar_to_something(t_env *env, t_com *com)
{
	char	*envvar;

	envvar = ft_strjoin(com->tab_command[1], "=");
	search_envvar_and_replace(env, envvar, com->tab_command[2]);
	free(envvar);
}

void	set_envvar_to_nothing(t_env *env, t_com *com)
{
	char	*envvar;

	envvar = ft_strjoin(com->tab_command[1], "=");
	search_envvar_and_replace(env, envvar, NULL);
	free(envvar);
}
