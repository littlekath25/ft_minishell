/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:29:26 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/17 11:16:04 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"

/*
	Change current working directory.
	If there is no path given, navigate to HOME.
	HOME from env is stored in t_shell.
*/
int	_cd_(char **argv)
{
	char	*path;

	if (g_shell->io_fds[0] != STDIN_FILENO || \
	g_shell->io_fds[1] != STDOUT_FILENO)
		return (0);
	if (argv[1])
		path = argv[1];
	else
		path = getenv("HOME");
	if (path != NULL && path[0] != '\0')
	{
		if (chdir(path) == -1)
		{
			printf("%s: %s: No such file or directory\n", argv[0], argv[1]);
			return (1);
		}
	}
	return (0);
}
