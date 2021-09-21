/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:29:26 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/21 16:23:21 by pspijkst      ########   odam.nl         */
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
	int	result;

	if (argv[1])
		result = chdir(argv[1]);
	else
		result = chdir(getenv("HOME"));
	if (result == -1)
	{
		printf("%s: %s: No such file or directory\n", argv[0], argv[1]);
		return (1);
	}
	return (0);
}
