/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:49:31 by mjose             #+#    #+#             */
/*   Updated: 2018/10/08 21:38:32 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_prompt(t_env *env, t_prompt *prompt)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;

	tmp1 = ft_strjoin(NAME_SHELL, " ");
	tmp2 = ft_strjoin(tmp1, VERSION);
	tmp3 = ft_strjoin(tmp2, " :: ");
	tmp4 = ft_strjoin(tmp3, ft_strrchr(env->path_current, '/'));
	prompt->prompt = ft_strjoin(tmp4, " -> ");
	free(tmp1);
	free(tmp2);
	free(tmp3);
	free(tmp4);
	ft_putstr(prompt->prompt);
	free(prompt->prompt);
	prompt->is_written = 1;
}

void	put_prompt_clean_line(t_env *env, t_prompt *prompt, t_com *com)
{
	ft_strdel(&prompt->line);
	prompt->have_line = 0;
	com->split.error = 0;
	put_prompt(env, prompt);
}
