/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/25 11:51:31 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/25 16:50:07 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_shell(char **env)
{
	char	*dup;

	g_shell = ft_calloc(1, sizeof(t_shell));
	if (!g_shell)
		error_and_exit(err_malloc);
	g_shell->env = vector_newptr();
	if (!g_shell->env)
		error_and_exit(err_malloc);
	while (*env)
	{
		dup = ft_strdup(*env);
		if (!dup)
			error_and_exit(err_malloc);
		if (vector_add(g_shell->env, dup) == false)
			error_and_exit(err_malloc);
		env++;
	}
}
