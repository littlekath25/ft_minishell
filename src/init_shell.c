/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/25 11:51:31 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/09 11:18:02 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <unistd.h>
#include <signal.h>

#ifdef __APPLE__

static char	***get_environ_ptr(void)
{
	extern char	**environ;

	return (&environ);
}

#else

static char	***get_environ_ptr(void)
{
	extern char	**__environ;

	return (&__environ);
}

#endif

void	init_shell(char **env)
{
	char	*dup;

	g_shell = ft_calloc(1, sizeof(t_shell));
	if (!g_shell)
		shell_exit(err_malloc);
	g_shell->env_list = vector_newptr();
	if (!g_shell->env_list)
		shell_exit(err_malloc);
	while (*env)
	{
		dup = ft_strdup(*env);
		if (!dup)
			shell_exit(err_malloc);
		if (vector_add(g_shell->env_list, dup) == false)
			shell_exit(err_malloc);
		env++;
	}
	g_shell->environ = get_environ_ptr();
	*g_shell->environ = vector_tostrarray(g_shell->env_list);
	if (!*g_shell->environ)
		shell_exit(err_malloc);
	// activate_signals();
}
