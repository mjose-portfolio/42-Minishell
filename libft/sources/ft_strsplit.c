/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:53:34 by mjose             #+#    #+#             */
/*   Updated: 2017/11/18 15:16:21 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n_parts;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	n_parts = ft_countparts((const char *)s, c);
	tab = (char **)malloc(sizeof(*tab) *
			(ft_countparts((const char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (n_parts--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0,
				ft_partlen((const char *)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_partlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
