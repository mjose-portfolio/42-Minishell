/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:59:49 by mjose             #+#    #+#             */
/*   Updated: 2018/10/15 18:39:27 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_type_cmd(char *cmd)
{
	if (ft_strequ(cmd, "env"))
		return (1);
	else if (ft_strequ(cmd, "cd"))
		return (2);
	else if (ft_strequ(cmd, "setenv"))
		return (3);
	else if (ft_strequ(cmd, "unsetenv"))
		return (4);
	else if (ft_strequ(cmd, "echo"))
		return (5);
	else if (ft_strequ(cmd, "exit"))
		return (-1);
	else if (!ft_strequ(cmd, "exit") && !ft_strequ(cmd, "") && cmd)
		return (0);
	return (-2);
}
