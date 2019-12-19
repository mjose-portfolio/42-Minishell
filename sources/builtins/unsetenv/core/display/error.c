/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 07:35:55 by mjose             #+#    #+#             */
/*   Updated: 2018/09/08 01:26:58 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_err_unsetenv_no_arguments(t_error *com_error)
{
	ft_putendl_fd("unsetenv: Too few arguments.", 2);
	com_error->err_return_com = 1;
}
