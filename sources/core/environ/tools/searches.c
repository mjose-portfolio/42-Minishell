/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:45:51 by mjose             #+#    #+#             */
/*   Updated: 2018/10/22 07:31:12 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_index_tab_env(t_env *env, char *value)
{
	int	i;

	i = 0;
	if (env->is_removed || !env->tab_env[0])
		return (-1);
	while (!ft_strnequ(env->tab_env[i], value, ft_strlen(value)))
		if (!env->tab_env[++i])
			break ;
	if (!env->tab_env[i])
		return (-1);
	return (i);
}
