/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:24:37 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/21 16:24:03 by pspijkst      ########   odam.nl         */
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
		exit(0);
	ft_putendl_fd(cwd, g_shell->io_fds[1]);
	return (0);
}
