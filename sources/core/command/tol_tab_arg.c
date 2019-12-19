/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tol_tab_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 02:39:05 by mjose             #+#    #+#             */
/*   Updated: 2018/10/23 00:37:52 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_home_char(t_com *com, t_env *env, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strdup(ft_strchr(com->tab_command[i], '~') + 1);
	tmp2 = ft_strjoin(env->path_home, "/");
	ft_strdel(&com->tab_command[i]);
	com->tab_command[i] = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

void	fill_next_quote(t_split *split)
{
	split->tab[split->i][split->pos++] = *split->s_dirt;
	split->s_dirt++;
}

void	init_without_quotes(t_split *split)
{
	crt_without_quotes(split);
	split->pos = 0;
	split->ctrl_quotes = 0;
}

void	init_with_quotes(t_split *split)
{
	crt_with_quotes(split);
	split->pos = 0;
	split->ctrl_quotes = 1;
}
