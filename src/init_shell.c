/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/25 11:51:31 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/25 15:52:14 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	st_init_vect(char **env)
{
	while (*env)
	{
		if (vector_add(g_shell->env.env, *env) == false)
			error_and_exit(err_malloc);
		env++;
	}
}

void	init_shell(char ***env)
{
	g_shell = ft_calloc(1, sizeof(t_shell));
	if (!g_shell)
		error_and_exit(err_malloc);
	g_shell->env.env = vector_newptr();
	if (!g_shell->env.env)
		error_and_exit(err_malloc);
	g_shell->env.bltin = env;
	st_init_vect(*env);
}
