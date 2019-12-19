/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 06:15:53 by mjose             #+#    #+#             */
/*   Updated: 2018/09/08 01:24:34 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_err_env_comnf(t_com *com, t_proc *proc)
{
	char	*error;

	error = ft_strjoin("minishell: command not found: ", com->tab_command[0]);
	ft_putendl_fd(error, 2);
	free(error);
	proc->stat_process = 0;
}
