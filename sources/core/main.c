/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:52:51 by mjose             #+#    #+#             */
/*   Updated: 2018/10/30 00:52:42 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_input(t_prompt *prompt, t_env *env, t_com *com)
{
	com->arguments = -1;
	if (!prompt->is_written)
		put_prompt_clean_line(env, prompt, com);
	else if (!prompt->have_line)
	{
		com->str_command = NULL;
		prompt->have_line = get_next_line(com->fd, &prompt->line);
		if (prompt->have_line && !ft_strequ(prompt->line, ""))
			create_command(env, prompt, com);
		if (com->arguments == -1)
			prompt->is_written = 1;
		if (com->str_command && ft_iswhitespace(com->str_command[0]))
			ft_strdel(&com->str_command);
	}
}

int		exec_or_exit(t_shell *shell)
{
	if (shell->prompt.have_line && shell->prompt.line &&
			check_type_cmd(shell->command.tab_command[0]) >= 0)
		exec_command(&shell->environ, &shell->prompt,
			&shell->command, &shell->process);
	else if (shell->prompt.have_line && shell->prompt.line &&
			check_type_cmd(shell->command.tab_command[0]) == -1)
		return (1);
	return (0);
}

void	read_and_exec(t_shell *shell)
{
	while (1)
	{
		wait_input(&shell->prompt, &shell->environ, &shell->command);
		if (shell->command.split.error || (shell->command.arguments == -1 &&
			shell->prompt.have_line))
			put_prompt_clean_line(&shell->environ, &shell->prompt,
				&shell->command);
		else if (shell->command.tab_command)
		{
			if (exec_or_exit(shell))
				break ;
		}
		else if (shell->prompt.line && ft_strequ(shell->prompt.line, ""))
		{
			shell->command.error_fd = 1;
			break ;
		}
	}
}

int		main(void)
{
	t_shell		shell;
	char		c;

	c = '\0';
	init_shell(&shell.environ, &shell.prompt, &shell.command);
	if (write(shell.command.fd, &c, 1) > 0)
		read_and_exec(&shell);
	else
		shell.command.error_fd = 1;
	clean_shell(&shell.environ, &shell.prompt, &shell.command);
	return (0);
}
