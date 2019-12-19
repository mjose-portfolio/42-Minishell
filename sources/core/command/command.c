/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:58:40 by mjose             #+#    #+#             */
/*   Updated: 2018/10/31 03:17:58 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rmv_comtab(t_com *com)
{
	int		i;

	i = 0;
	if (com->tab_command)
	{
		while (com->tab_command[i])
			ft_strdel(&com->tab_command[i++]);
		free(com->tab_command);
		com->tab_command = NULL;
	}
	ft_strdel(&com->str_command);
}

void	chk_error_quotes(t_com *com)
{
	if (com->split.error)
	{
		rmv_comtab(com);
		put_err_com_quotes_not_closed();
	}
	if (!com->tab_command || !com->tab_command[0])
	{
		ft_strdel(&com->str_command);
		free(com->tab_command);
		com->tab_command = NULL;
	}
}

void	chk_tab_command(t_env *env, t_com *com)
{
	int		i;

	i = 0;
	if (com->tab_command)
		while (com->tab_command[i])
		{
			if (com->tab_command[i][0] == '~')
			{
				if (ft_strequ(com->tab_command[i], "~") ||
						ft_strequ(com->tab_command[i], "~/"))
					ft_strreplace(&com->tab_command[i], "~");
				else
				{
					if (env->path_home)
						replace_home_char(com, env, i);
					else
						ft_strreplace(&com->tab_command[i], "~");
				}
			}
			i++;
		}
}

int		count_com_arguments(char **command)
{
	int		count;

	if (command)
	{
		count = 1;
		if (command[count])
			while (command[count])
				count++;
		return (count - 1);
	}
	else
		return (0);
}

void	create_command(t_env *env, t_prompt *prompt, t_com *com)
{
	char	*tmp3;
	char	*tmp4;

	com->error_fd = 0;
	tmp3 = ft_strtrim(prompt->line);
	tmp4 = prepare_new_string(tmp3);
	com->str_command = conv_whites_str(tmp4);
	free(tmp3);
	com->tab_command = split_line(com->str_command, ' ',
		tmp4, &com->split);
	free(tmp4);
	com->arguments = count_com_arguments(com->tab_command);
	chk_error_quotes(com);
	chk_tab_command(env, com);
}
