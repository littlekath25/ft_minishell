/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/25 11:51:31 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/17 12:25:47 by pspijkst      ########   odam.nl         */
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
	g_shell->io_fds[0] = STDIN_FILENO;
	g_shell->io_fds[1] = STDOUT_FILENO;
	tcgetattr(STDIN_FILENO, &g_shell->dfl_attr);
}
