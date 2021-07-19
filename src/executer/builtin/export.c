/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 11:33:10 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/builtin.h"
#include "includes/shell.h"

/*
	Sets environment variable.
*/
void	_export_(char **argv)
{
	int		i;

	if (argv[0] == 0)
		_env_(argv);
	i = vector_indexof(g_shell->env, argv[1], ft_strlen(argv[1]));
	if (i != -1)
		vector_removeat(g_shell->env, i);
	vector_add(g_shell->env, argv[1]);
}
