/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:04:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/21 16:22:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../../includes/shell.h"

/*
	Prints all environment variables in environment variables list.
	This means key-value paired variabled.
*/
int	_env_(char **argv)
{
	char	**env;

	(void)argv;
	env = *g_shell->environ;
	if (!env)
		return (0);
	while (*env)
	{
		if (ft_strchr(*env, '='))
			ft_putendl_fd(*env, g_shell->io_fds[1]);
		env++;
	}
	return (0);
}
