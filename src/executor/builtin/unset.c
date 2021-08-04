/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 18:06:07 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/04 13:43:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "shell.h"

/*
	Each variable or function specified in argv shall be unset.
	Ignores an argument if the variable was not set.
*/
void	_unset_(char **argv)
{
	int	i;

	argv++;
	while (*argv)
	{
		if (is_valid_key(*argv))
		{
			i = vector_indexof(g_shell->env_list, *argv);
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
}
