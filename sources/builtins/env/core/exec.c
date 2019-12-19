/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:47:15 by mjose             #+#    #+#             */
/*   Updated: 2018/10/31 05:26:27 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_envchild_other(t_com *com, t_env_tmp *env, t_proc *proc)
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

void	exec_envchild_command_path(t_com *com, t_env_tmp *env, t_proc *proc)
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
			ft_strdel(&tmp_path);
		}
	put_err_comnf(com, proc, tmp_com);
}

void	exec_envchild(t_env_tmp *env_tmp)
{
	t_proc	proc;

	if ((env_tmp->env_com.tab_command[0][0] == '.' &&
			env_tmp->env_com.tab_command[0][1] == '/') ||
			env_tmp->env_com.tab_command[0][0] == '/' ||
			env_tmp->env_com.tab_command[0][0] == '~')
		exec_envchild_other(&env_tmp->env_com, env_tmp, &proc);
	else
		exec_envchild_command_path(&env_tmp->env_com, env_tmp, &proc);
}

void	exec_env_command(t_env_tmp *env_tmp, t_com *com, int arg)
{
	int		first_arg;
	int		i;

	i = 0;
	first_arg = arg;
	while (com->tab_command[arg])
		arg++;
	env_tmp->env_com.tab_command = (char **)malloc(sizeof(char *) *
		(arg - first_arg + 2));
	while (com->tab_command[first_arg])
	{
		check_arg_for_envchild(first_arg, i, env_tmp, com);
		i++;
		first_arg++;
	}
	env_tmp->env_com.tab_command[i] = NULL;
	exec_envchild(env_tmp);
	i = 0;
	while (env_tmp->env_com.tab_command[i])
		ft_strdel(&env_tmp->env_com.tab_command[i++]);
	free(env_tmp->env_com.tab_command);
}

void	exec_env(t_env *env, t_com *com)
{
	int		arg;

	arg = 1;
	init_envtmp(&env->env_tmp);
	if (com->arguments)
		crt_environ_tmp(env, &env->env_tmp, com->tab_command[1]);
	else
		crt_environ_tmp(env, &env->env_tmp, NULL);
	if (!com->arguments)
		print_env_tmp(&env->env_tmp);
	else
	{
		if (ft_strequ(com->tab_command[arg], "-i"))
			arg++;
		while (is_for_chg_env_tmp(com->tab_command[arg]))
			set_envtmpvar(&env->env_tmp, com->tab_command[arg++]);
		if (!com->arguments || (env->env_tmp.tab_env && !com->tab_command[arg]))
			print_env_tmp(&env->env_tmp);
		else if (com->tab_command[arg] && com->tab_command[arg][0] != '-')
			exec_env_command(&env->env_tmp, com, arg);
	}
	if (env->env_tmp.tab_env)
		rmv_environ_tmp(&env->env_tmp);
}
