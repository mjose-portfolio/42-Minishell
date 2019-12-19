/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:41:50 by mjose             #+#    #+#             */
/*   Updated: 2018/10/31 05:24:53 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_err_com_quotes_not_closed(void)
{
	char	*error;

	error = "minishell: command not supported, quotes must always be even.";
	ft_putendl_fd(error, 2);
}

void	put_err_comnp(char *path, t_proc *proc)
{
	char	*error;

	error = ft_strjoin(path, ": Permission denied.");
	ft_putendl_fd(error, 2);
	free(error);
	proc->stat_process = 0;
}

void	put_err_comnf(t_com *com, t_proc *proc, char *tmp_com)
{
	char	*error;

	error = ft_strjoin("minishell: command not found: ", com->tab_command[0]);
	ft_putendl_fd(error, 2);
	free(error);
	proc->stat_process = 0;
	ft_strdel(&tmp_com);
}
