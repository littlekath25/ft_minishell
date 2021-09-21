/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 18:06:07 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/21 16:21:18 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "shell.h"

/*
	Each variable or function specified in argv shall be unset.
	Ignores an argument if the variable was not set.
*/
int	_unset_(char **argv)
{
	int	i;

	argv++;
	while (*argv)
	{
		if (is_valid_key(*argv))
		{
			i = env_list_indexof(g_shell->env_list, *argv);
			if (i != -1)
			{
				free(vector_getvalue(g_shell->env_list, i));
				vector_removeat(g_shell->env_list, i);
			}
		}
		argv++;
	}
	free(*g_shell->environ);
	*g_shell->environ = vector_tostrarray(g_shell->env_list);
	if (!*g_shell->environ)
		shell_exit(err_malloc);
	return (0);
}
