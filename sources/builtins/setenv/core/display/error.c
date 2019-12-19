/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 02:49:38 by mjose             #+#    #+#             */
/*   Updated: 2018/09/08 01:26:13 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_err_setenv_not_valid_name(t_error *com_error)
{
	char	*building;
	char	*desc;
	char	*error;

	building = "setenv:";
	desc = " Variable name must contain alphanumeric characters.";
	error = ft_strjoin(building, desc);
	ft_putendl_fd(error, 2);
	com_error->err_return_com = 1;
	free(error);
}

void	put_err_setenv_alpha(t_error *com_error)
{
	ft_putendl_fd("setenv: Variable name must begin with a letter.", 2);
	com_error->err_return_com = 1;
}

void	put_err_setenv_arguments(t_error *com_error)
{
	ft_putendl_fd("setenv: Too many arguments.", 2);
	com_error->err_return_com = 1;
}
