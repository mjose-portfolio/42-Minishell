/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 00:03:26 by mjose             #+#    #+#             */
/*   Updated: 2018/10/30 01:06:05 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_err_cd_str_not_pwd(t_cd *cd)
{
	char	*error;

	error = ft_strjoin("cd: string not in pwd: ", cd->arg);
	ft_putendl_fd(error, 2);
	ft_strdel(&error);
}

void	put_err_cd_no_permission(char *obj)
{
	char	*error;

	error = ft_strjoin("cd: permission denied: ", obj);
	ft_putendl_fd(error, 2);
	ft_strdel(&error);
}

void	put_err_cd_no_dir(char *obj)
{
	char	*error;

	error = ft_strjoin("cd: not a directory: ", obj);
	ft_putendl_fd(error, 2);
	ft_strdel(&error);
}

void	put_err_cd_file_or_dir_noexist(char *obj)
{
	char	*error;

	error = ft_strjoin("cd: no such file or directory: ", obj);
	ft_putendl_fd(error, 2);
	ft_strdel(&error);
}

void	put_err_cd_var_notset(t_com *com, char *envvar, t_env *env)
{
	t_error	error;
	int		i;

	i = 0;
	error.error = (char **)malloc(sizeof(char *) * 6);
	error.error[0] = ft_strdup("minishell: ");
	error.error[1] = ft_strjoin(error.error[0], com->tab_command[0]);
	error.error[2] = ft_strjoin(error.error[1], ": ");
	error.error[3] = ft_strjoin(error.error[2], envvar);
	error.error[4] = ft_strjoin(error.error[3], " not set");
	error.error[5] = NULL;
	ft_putendl_fd(error.error[4], 2);
	while (error.error[i])
		ft_strdel(&error.error[i++]);
	free(error.error);
	env->err_env_home = env->err_env_home + 0;
}
