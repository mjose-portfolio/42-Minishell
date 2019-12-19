/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_tab_arg_crt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 02:17:27 by mjose             #+#    #+#             */
/*   Updated: 2018/10/22 06:57:41 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	crt_without_quotes(t_split *split)
{
	init_crt_without_quotes(split);
	while (split->s_dirt[split->to] &&
		!ft_iswhitespace(split->s_dirt[split->to]))
	{
		if (split->s_dirt[split->to] == '"' && !split->ctrl_quotes)
		{
			split->pos--;
			split->ctrl_quotes = 1;
		}
		split->to++;
		split->pos++;
		if (split->ctrl_quotes)
		{
			while (split->s_dirt[split->to] && split->s_dirt[split->to] != '"')
			{
				split->to++;
				split->pos++;
			}
			split->ctrl_quotes = 0;
			split->to++;
			split->pos--;
		}
	}
	split->tab[split->i] = ft_strnew(split->pos + 1);
}

void	check_for_null(t_split *split)
{
	if (split->pos > -1)
		split->tab[split->i] = ft_strnew(split->pos + 1);
	else
		split->tab[split->i] = NULL;
}

void	crt_with_quotes(t_split *split)
{
	init_crt_with_quotes(split);
	while (split->s_dirt[split->to] && split->ctrl_quotes)
	{
		split->to++;
		while (split->s_dirt[split->to] && split->s_dirt[split->to] != '"')
			go_to_next_quote(split);
		split->ctrl_quotes = 0;
		skip_quote(split);
		if (split->s_dirt[split->to] && split->s_dirt[split->to] == '"')
			split->ctrl_quotes = 1;
		else if (split->s_dirt[split->to] &&
			!ft_iswhitespace(split->s_dirt[split->to]))
			while (split->s_dirt[split->to] &&
				!ft_iswhitespace(split->s_dirt[split->to]))
			{
				go_to_next_quote(split);
				if (split->s_dirt[split->to] && split->s_dirt[split->to] == '"')
				{
					split->ctrl_quotes = 1;
					split->pos--;
					break ;
				}
			}
	}
	check_for_null(split);
}
