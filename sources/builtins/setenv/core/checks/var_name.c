/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:03:56 by mjose             #+#    #+#             */
/*   Updated: 2018/09/08 01:26:04 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_var_name_is_alphanum(t_com *com)
{
	int		i;

	i = 0;
	while (com->tab_command[1][i])
		if (ft_isalpha(com->tab_command[1][i]) ||
				com->tab_command[1][i] == '_')
			i++;
		else
			return (0);
	return (1);
}
