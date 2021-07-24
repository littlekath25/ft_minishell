/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:29:26 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 15:03:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../includes/shell.h"

/*
	Change current working directory.
	If there is no path given, navigate to HOME.
	HOME from env is stored in t_shell.
*/
void	_cd_(char **argv)
{
	if (argv[1])
		chdir(argv[1]);
	else
		chdir(getenv("HOME"));
}
