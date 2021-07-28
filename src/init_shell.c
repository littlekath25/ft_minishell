/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/25 11:51:31 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/28 10:58:50 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#ifdef __APPLE__

void	get_environ_ptr(void)
{
	extern char	**environ;

	g_shell->environ = &environ;
}

#else

void	get_environ_ptr(void)
{
	extern char	**__environ;

	g_shell->environ = &__environ;
}

#endif

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
	get_environ_ptr();
	*g_shell->environ = vector_tostrarray(g_shell->env);
	if (!*g_shell->environ)
		error_and_exit(err_malloc);
}
