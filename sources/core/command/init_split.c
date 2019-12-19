/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:50:03 by mjose             #+#    #+#             */
/*   Updated: 2018/10/22 06:07:00 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_split(char *s, char c, char *s_dirt, t_split *split)
{
	split->s = s;
	split->s_dirt = s_dirt;
	split->c = c;
	split->i = 0;
	split->n_parts = countparts(split->s, split->c);
	split->tab = NULL;
	if (s && !ft_iswhitespace(split->s[0]))
		split->tab = (char **)malloc(sizeof(char *) * (split->n_parts + 1));
	split->ctrl_quotes = 0;
}
