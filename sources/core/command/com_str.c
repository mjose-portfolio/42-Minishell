/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 05:48:40 by mjose             #+#    #+#             */
/*   Updated: 2018/09/14 09:55:59 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	chg_ifwhitespace(char c)
{
	if (ft_iswhitespace(c))
		return (' ');
	else
		return (c);
}

char	*chg_simple_quotes(char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		if (s[i] == '\'')
			new_str[i] = '"';
		else
			new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*prepare_new_string(char *s)
{
	char	*new_str;

	new_str = NULL;
	new_str = chg_simple_quotes(s);
	return (new_str);
}

char	*conv_whites_str(char *s)
{
	int		i;
	int		pos;
	int		c;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		pos = i;
		if (s[i] == '"')
		{
			c = i;
			new_str[c++] = s[i++];
			while (s[i] && s[i] != '"')
				new_str[c++] = s[i++];
			if (!s[i])
				i = pos;
		}
		new_str[i] = chg_ifwhitespace(s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
