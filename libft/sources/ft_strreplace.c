/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 00:45:20 by mjose             #+#    #+#             */
/*   Updated: 2018/10/23 00:51:40 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char **ap, char *new_str)
{
	char	*tmp;

	ft_strdel(ap);
	tmp = ft_strdup(new_str);
	ap = &tmp;
}
