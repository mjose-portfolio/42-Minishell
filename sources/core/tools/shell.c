/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:04:55 by mjose             #+#    #+#             */
/*   Updated: 2018/10/30 00:51:22 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_shell(t_env *env, t_prompt *prompt, t_com *com)
{
	char	*error;

	error = ft_strdup("minishell: Execution after PIPE is not allowed. Exit.");
	ft_strdel(&prompt->line);
	rmv_environ(env);
	if (!com->error_fd)
		rmv_comtab(com);
	else
		ft_putendl_fd(error, 2);
	free(error);
}

void	init_shell(t_env *env, t_prompt *prompt, t_com *com)
{
	prompt->is_written = 0;
	prompt->line = NULL;
	prompt->have_line = 0;
	com->tab_command = NULL;
	com->fd = open("/dev/fd/0", O_RDWR);
	com->error_fd = 0;
	crt_environ(env);
}
