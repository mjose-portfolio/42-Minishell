/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 00:35:44 by mjose             #+#    #+#             */
/*   Updated: 2018/10/18 02:15:54 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_count_parts	chk_forcountparts(t_count_parts counts)
{
	if (*counts.s == '"')
	{
		counts.s++;
		counts.i++;
		while (*counts.s != '"' && *counts.s)
		{
			counts.s++;
			counts.i++;
		}
		if (!counts.s)
			counts.s = counts.s - counts.i;
		counts.i = 0;
	}
	return (counts);
}

int				countparts(char *s, char c)
{
	t_count_parts	counts;

	counts.subs = 0;
	counts.cnt = 0;
	counts.i = 0;
	counts.s = s;
	counts.c = c;
	while (*counts.s != '\0')
	{
		if (counts.subs == 1 && (*counts.s == counts.c || *counts.s == '"'))
			counts.subs = 0;
		if (counts.subs == 0 && (*counts.s != counts.c || *counts.s != '"'))
		{
			counts = chk_forcountparts(counts);
			counts.subs = 1;
			counts.cnt++;
		}
		if (*counts.s)
		{
			counts.s++;
			counts.cnt++;
		}
	}
	return (counts.cnt);
}

char			**split_line(char *s, char c, char *s_dirt, t_split *split)
{
	if (!s)
		return (NULL);
	init_split(s, c, s_dirt, split);
	if (!split->tab)
		return (NULL);
	return (fill_tab(split));
}
