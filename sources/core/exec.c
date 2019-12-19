/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:20:04 by mjose             #+#    #+#             */
/*   Updated: 2018/10/31 05:26:02 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		test_existence_and_clean(t_proc *proc, char *tmp_path, char *tmp_com)
{
	if (!access(tmp_path, F_OK))
	{
		put_err_comnp(tmp_path, proc);
		ft_strdel(&tmp_path);
		ft_strdel(&tmp_com);
		return (1);
	}
	ft_strdel(&tmp_path);
	return (0);
}

void	exec_child_command_path(t_com *com, t_env *env, t_proc *proc)
{
	int		i;
	char	*tmp_com;
	char	*tmp_path;
	pid_t	father;

	i = 0;
	tmp_com = ft_strjoin("/", com->tab_command[0]);
	if (env->tab_exec && !ft_strequ(com->tab_command[0], ".") &&
			!ft_strequ(com->tab_command[0], ".."))
		while (env->tab_exec[i])
		{
			tmp_path = ft_strjoin(env->tab_exec[i++], tmp_com);
			if (!access(tmp_path, X_OK))
			{
				if ((father = fork()) == 0)
					execve(tmp_path, com->tab_command, env->tab_env);
				ft_strdel(&tmp_path);
				wait(&proc->stat_process);
				free(tmp_com);
				return ;
			}
			else if (test_existence_and_clean(proc, tmp_path, tmp_com))
				return ;
		}
	put_err_comnf(com, proc, tmp_com);
}

void	exec_child_other(t_com *com, t_env *env, t_proc *proc)
{
	char	*error;
	pid_t	father;

	if (!access(com->tab_command[0], X_OK))
	{
		if ((father = fork()) == 0)
			execve(com->tab_command[0], com->tab_command, env->tab_env);
		wait(&proc->stat_process);
		return ;
	}
	error = ft_strjoin("minishell: command not found: ", com->tab_command[0]);
	ft_putendl_fd(error, 2);
	free(error);
}

void	exec_child(t_com *com, t_env *env, t_proc *proc)
{
	check_arg_for_child(com, env);
	if ((com->tab_command[0][0] == '.' && com->tab_command[0][1] == '/') ||
			com->tab_command[0][0] == '/' || com->tab_command[0][0] == '~')
		exec_child_other(com, env, proc);
	else
		exec_child_command_path(com, env, proc);
}

void	exec_command(t_env *env, t_prompt *prompt, t_com *com, t_proc *proc)
{
	if (check_type_cmd(com->tab_command[0]) > 0)
	{
		exec_builtin(com, env);
		prompt->have_line = 0;
		ft_strdel(&prompt->line);
		put_prompt(env, prompt);
	}
	else if (check_type_cmd(com->tab_command[0]) == 0)
	{
		exec_child(com, env, proc);
		prompt->have_line = 0;
		ft_strdel(&prompt->line);
		if (WIFEXITED(proc->stat_process))
			put_prompt(env, prompt);
	}
	rmv_comtab(com);
}
