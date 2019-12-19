/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tol_tab_arg_crt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 03:53:18 by mjose             #+#    #+#             */
/*   Updated: 2018/10/18 04:26:25 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_quote(t_split *split)
{
	split->to++;
	split->pos--;
}

void	go_to_next_quote(t_split *split)
{
	split->to++;
	split->pos++;
}

void	init_crt_without_quotes(t_split *split)
{
	split->pos = 0;
	split->ctrl_quotes = 0;
}

void	init_crt_with_quotes(t_split *split)
{
	split->pos = 0;
	split->ctrl_quotes = 1;
}
