/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:58:30 by mjose             #+#    #+#             */
/*   Updated: 2017/11/09 14:45:09 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;

	i = 0;
	while (len > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		--len;
		i++;
	}
	while (len > 0)
	{
		dst[i] = '\0';
		--len;
		i++;
	}
	return (dst);
}
