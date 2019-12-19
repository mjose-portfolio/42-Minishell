/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:54:11 by mjose             #+#    #+#             */
/*   Updated: 2017/11/17 15:58:27 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int value, int base)
{
	int	len;

	len = (value == 0) ? 1 : 0;
	if (value < 0)
	{
		len = (base == 10) ? 2 : 1;
		value = value / base;
		value = -value;
	}
	while (value > 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}
