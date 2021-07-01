/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:29:26 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 18:34:42 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Change current working directory.
	If there is no path given, navigate to HOME.
	HOME from env is stored in t_shell.
*/
void	_cd_(char **argv)
{
	chdir(argv[1]);
}
