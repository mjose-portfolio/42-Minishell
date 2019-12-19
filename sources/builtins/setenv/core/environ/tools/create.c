/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 01:24:33 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 01:27:30 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_new_path_var(char *value, t_env *env)
{
	if (value)
		env->tab_exec = ft_strsplit(value, ':');
	else
		env->tab_exec = NULL;
}
