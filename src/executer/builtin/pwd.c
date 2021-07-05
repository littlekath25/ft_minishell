/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:24:37 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 18:34:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
	Print the current working directory.
*/
void	_pwd_(char **argv)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		exit(0);
	printf("%s\n", cwd);
}
