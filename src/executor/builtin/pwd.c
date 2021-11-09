/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:24:37 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/03 15:59:46 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

/*
	Print the current working directory.
*/
int	_pwd_(char **argv)
{
	char	*cwd;
	char	buff[1000];

	(void)argv;
	cwd = getcwd(buff, 1000);
	if (!cwd)
		shell_exit(err_pwd);
	ft_putendl_fd(cwd, g_shell->io_fds[1]);
	return (0);
}
