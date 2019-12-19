/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_tab_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:19:09 by mjose             #+#    #+#             */
/*   Updated: 2018/10/22 06:35:27 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	scan_for_quotes(t_split *split)
{
	int		i;

	i = 0;
	split->ctrl_quotes = 0;
	split->error = 0;
	while (split->s_dirt[i])
	{
		if (split->s_dirt[i] == '"')
			split->ctrl_quotes++;
		i++;
	}
	if (split->ctrl_quotes % 2 != 0)
		split->error = 1;
}

void	fill_without_quotes(t_split *split)
{
	init_without_quotes(split);
	while (*split->s_dirt && !ft_iswhitespace(*split->s_dirt))
	{
		if (*split->s_dirt == '"' && !split->ctrl_quotes)
		{
			split->s_dirt++;
			split->ctrl_quotes = 1;
		}
		split->tab[split->i][split->pos++] = *split->s_dirt;
		split->s_dirt++;
		if (split->ctrl_quotes)
		{
			while (*split->s_dirt && *split->s_dirt != '"')
			{
				split->tab[split->i][split->pos++] = *split->s_dirt;
				split->s_dirt++;
			}
			split->ctrl_quotes = 0;
			split->s_dirt++;
			split->ctrl_quotes--;
		}
	}
	split->tab[split->i][split->pos] = '\0';
}

void	fill_with_quotes(t_split *split)
{
	init_with_quotes(split);
	while (*split->s_dirt && split->ctrl_quotes)
	{
		split->s_dirt++;
		while (*split->s_dirt && *split->s_dirt != '"')
			fill_next_quote(split);
		split->ctrl_quotes = 0;
		split->s_dirt++;
		if (*split->s_dirt && *split->s_dirt == '"')
			split->ctrl_quotes = 1;
		else if (*split->s_dirt && !ft_iswhitespace(*split->s_dirt))
			while (*split->s_dirt && !ft_iswhitespace(*split->s_dirt))
			{
				fill_next_quote(split);
				if (*split->s_dirt && *split->s_dirt == '"')
				{
					split->ctrl_quotes = 1;
					break ;
				}
			}
	}
	if (split->tab[split->i])
		split->tab[split->i][split->pos] = '\0';
}

void	fill_arg(t_split *split)
{
	split->to = 0;
	while (*split->s_dirt && ft_iswhitespace(*split->s_dirt))
		split->s_dirt++;
	if (*split->s_dirt && *split->s_dirt != '"')
		fill_without_quotes(split);
	else if (*split->s_dirt && *split->s_dirt == '"')
		fill_with_quotes(split);
}

char	**fill_tab(t_split *split)
{
	split->i = 0;
	scan_for_quotes(split);
	if (!split->error)
		while (*split->s_dirt)
		{
			fill_arg(split);
			split->tab[++split->i] = NULL;
		}
	else
	{
		free(split->tab);
		split->tab = NULL;
	}
	return (split->tab);
}
