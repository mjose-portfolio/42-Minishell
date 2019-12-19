/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:59:14 by mjose             #+#    #+#             */
/*   Updated: 2017/11/15 12:14:54 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		size;

	size = 0;
	while ((*s1 || *s2) && n-- > 0)
		if ((size = (*(unsigned char *)s1++) - (*(unsigned char *)s2++)) != 0)
			return (size);
	return (size);
}
