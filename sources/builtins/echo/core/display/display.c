/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:16:53 by mjose             #+#    #+#             */
/*   Updated: 2018/10/17 04:31:30 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_value(char *value, char *real_value, t_env *env)
{
	char	*new_str;

	if (ft_strequ(real_value, "~") || real_value[0] == '$')
		new_str = ft_strdup(ft_strchr(value, '=') + 1);
	else if (real_value[0] == '~' && real_value[1] == '/')
		new_str = ft_strjoin(env->path_home, ft_strchr(real_value,
			real_value[1]));
	else
		new_str = ft_strdup(real_value);
	ft_putstr(new_str);
	free(new_str);
}

void	print_varenv_echo(t_env *env, char *string, char *arg)
{
	int		i;
	char	*new_str;
	char	*var;

	i = 1;
	new_str = ft_strnew(ft_strlen(string) - 1);
	while (string[i])
	{
		new_str[i - 1] = string[i];
		i++;
	}
	new_str[i - 1] = '\0';
	var = ft_strjoin(new_str, "=");
	i = search_index_tab_env(env, var);
	if (i >= 0)
		print_value(env->tab_env[i], arg, env);
	free(new_str);
	free(var);
}
