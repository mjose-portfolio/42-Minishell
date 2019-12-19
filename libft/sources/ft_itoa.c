/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:44:24 by mjose             #+#    #+#             */
/*   Updated: 2017/11/17 16:01:38 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*fresh;

	neg = 1;
	len = ft_intlen(n, 10);
	if (!(fresh = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		fresh[0] = '0';
	fresh[len] = '\0';
	while (n != 0)
	{
		if (n < 0)
		{
			fresh[0] = '-';
			neg = -1;
		}
		fresh[len - 1] = (((n % 10) * neg)) + '0';
		n = (n / 10);
		len--;
	}
	return (fresh);
}
