/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chg_dir_with_return.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 02:35:41 by mjose             #+#    #+#             */
/*   Updated: 2018/10/23 05:37:28 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*chg_dir_to_envvar_and_return_oldpwd(char *envr, t_env *env,
	t_com *com, t_cd *cd)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_strnew(ft_strlen(envr) + 2);
	while (envr[i] != '=' && envr[i])
	{
		tmp[i] = envr[i];
		i++;
	}
	tmp[i] = '=';
	tmp[i + 1] = '\0';
	free(envr);
	if ((i = search_index_tab_env(env, tmp)) >= 0)
	{
		free(tmp);
		ft_strdel(&cd->arg);
		cd->arg = ft_strdup(ft_strchr(env->tab_env[i], '=') + 1);
		aply_flag(cd, cd->arg);
		return (chg_dir_and_return_oldpwd(cd->arg, env));
	}
	free(tmp);
	chg_dir_to_home(env, com, cd);
	return (NULL);
}

char	*chg_dir_and_return_oldpwd(char *new_dir, t_env *env)
{
	char		*oldpwd;
	struct stat	stat_obj;

	if (stat(new_dir, &stat_obj) != -1)
	{
		if (stat_obj.st_mode & S_IFDIR)
		{
			if (!access(new_dir, R_OK))
			{
				chg_dir(new_dir, env);
				set_pwd_to_curdir(env);
				oldpwd = ft_strdup(new_dir);
				return (oldpwd);
			}
			put_err_cd_no_permission(new_dir);
			return (NULL);
		}
		put_err_cd_no_dir(new_dir);
		return (NULL);
	}
	put_err_cd_file_or_dir_noexist(new_dir);
	return (NULL);
}
