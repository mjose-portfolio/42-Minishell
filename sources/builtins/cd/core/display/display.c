/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 04:50:42 by mjose             #+#    #+#             */
/*   Updated: 2018/10/31 05:44:51 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_if_root_dir(t_cd *cd, char *new_dir, char *tmp)
{
	int		to_cpy;

	if (!ft_strequ(tmp, new_dir))
	{
		to_cpy = (ft_strlen(new_dir) - ft_strlen(tmp)) + 1;
		ft_strdel(&cd->arg);
		cd->arg = ft_strnew(to_cpy);
		cd->arg = ft_strncpy(cd->arg, new_dir, to_cpy - 1);
		cd->arg[to_cpy] = '\0';
	}
	else
	{
		ft_strdel(&cd->arg);
		cd->arg = ft_strdup("/");
	}
}

void	check_prev_dir(t_cd *cd, char *dir, t_env *env)
{
	char	*new_dir;
	char	*tmp;
	int		i;

	if (ft_strequ(dir, ".."))
	{
		if ((i = search_index_tab_env(env, "PWD=")) >= 0)
		{
			new_dir = ft_strdup(ft_strchr(env->tab_env[i], '=') + 1);
			tmp = ft_strdup(ft_strrchr(new_dir, '/'));
		}
		else
		{
			new_dir = giveme_curpath();
			tmp = ft_strdup(ft_strrchr(new_dir, '/'));
		}
		check_if_root_dir(cd, new_dir, tmp);
		free(new_dir);
		free(tmp);
	}
}

void	aply_flag(t_cd *cd, char *dir)
{
	struct stat inf;
	char		*new_path;
	char		*to_free;
	char		*to_free2;

	if (cd->opt_l)
		if (lstat(dir, &inf) != -1)
		{
			if (S_ISLNK(inf.st_mode))
			{
				to_free = giveme_curpath();
				to_free2 = ft_strjoin(to_free, "/");
				new_path = ft_strjoin(to_free2, cd->arg);
				ft_strdel(&cd->arg);
				cd->arg = new_path;
				free(to_free);
				free(to_free2);
			}
			else if (!cd->opt_p)
			{
				cd->opt_l = 0;
				cd->no_opt = 1;
			}
		}
}

void	display_cur_dir(t_env *env)
{
	ft_putendl(env->path_current);
}
