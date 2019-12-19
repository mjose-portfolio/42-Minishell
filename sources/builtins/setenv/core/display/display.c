/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:19:56 by mjose             #+#    #+#             */
/*   Updated: 2018/10/13 14:59:08 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env *env)
{
	int		i;

	if (!env->is_removed && env->tab_env[0])
	{
		i = 0;
		while (env->tab_env[i])
			ft_putendl(env->tab_env[i++]);
	}
}
