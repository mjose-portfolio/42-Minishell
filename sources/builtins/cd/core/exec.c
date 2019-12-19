/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 07:11:45 by mjose             #+#    #+#             */
/*   Updated: 2018/10/23 06:30:04 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_args(int i, t_cd *cd)
{
	if ((cd->opt_l && cd->opt_p && i - 3 == cd->last_flag) ||
			(!cd->opt_l && !cd->opt_p && i - 2 == cd->last_flag))
	{
		cd->error = 1;
		put_err_cd_str_not_pwd(cd);
		return ;
	}
	else if ((cd->opt_l && cd->opt_p && i - 3 > cd->last_flag)
				|| (!cd->opt_l && !cd->opt_p && i - 2 >= cd->last_flag))
	{
		cd->error = 1;
		put_err_cd_many_args();
		return ;
	}
	else
	{
		if (!cd->opt_l && !cd->opt_p)
			cd->no_opt = 1;
	}
}

void	check_if_flag(t_com *com, t_cd *cd, int i, int j)
{
	if (com->tab_command[i][j] == 'L')
		cd->opt_l = 1;
	else if (com->tab_command[i][j] == 'P')
		cd->opt_p = 1;
	else if (com->tab_command[i][j])
	{
		cd->no_opt = 1;
		cd->opt_l = 0;
		cd->opt_p = 0;
	}
}

void	check_cd_args(t_cd *cd, t_com *com)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (com->tab_command[i])
	{
		if (!ft_strequ(com->tab_command[i], "-") &&
			com->tab_command[i][j] == '-')
		{
			j++;
			while (com->tab_command[i][j] && !cd->no_opt)
				check_if_flag(com, cd, i, j++);
			if (cd->no_opt)
				cd->arg = ft_strdup(com->tab_command[i]);
			else
				cd->last_flag = i;
		}
		j = 0;
		if ((!cd->arg && com->tab_command[i][0] != '-') ||
				ft_strequ(com->tab_command[i], "-"))
			cd->arg = ft_strdup(com->tab_command[i]);
		i++;
	}
	check_args(i, cd);
}

void	init_cd(t_cd *cd, t_com *com)
{
	cd->no_opt = 0;
	cd->opt_l = 0;
	cd->opt_p = 0;
	cd->arg = NULL;
	cd->last_flag = 1;
	cd->error = 0;
	check_cd_args(cd, com);
}

void	check_and_chg_dir(t_env *env, t_com *com)
{
	t_built_opt		opt;

	init_cd(&opt.cd, com);
	if (!opt.cd.error)
	{
		if (!opt.cd.arg || ft_strequ(opt.cd.arg, "~") ||
				ft_strequ(opt.cd.arg, "$HOME") || opt.cd.arg[0] == '~')
			chg_dir_to_home(env, com, &opt.cd);
		else if (ft_strequ(opt.cd.arg, "-"))
			chg_dir_to_oldpwd(env, com);
		else if (opt.cd.arg[0] == '$')
			chg_dir_to_envvar(env, com, &opt.cd);
		else if (opt.cd.arg)
			chg_dir_to_input(env, &opt.cd);
	}
	if (opt.cd.arg)
		ft_strdel(&opt.cd.arg);
}
