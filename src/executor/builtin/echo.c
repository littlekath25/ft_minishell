/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:39:36 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/03 15:09:55 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "shell.h"

/*
	Print the argument specified in argv to the stdout.
	-n flag removes the trailing newline.
*/
int	_echo_(char **argv)
{
	char	newline;
	int		i;

	newline = 1;
	argv++;
	while (*argv && (*argv)[0] == '-' && (*argv)[1] == 'n')
	{
		i = 2;
		while ((*argv)[i] == 'n')
			i++;
		if ((*argv)[i] != '\0')
			break ;
		newline = 0;
		argv++;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv, g_shell->io_fds[1]);
		argv++;
		if (*argv)
			write(g_shell->io_fds[1], " ", 1);
	}
	if (newline)
		write(g_shell->io_fds[1], "\n", 1);
	return (0);
}
