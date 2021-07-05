/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:04:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 18:34:37 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
	Print env.
	Env is loaded on startup and is stored in t_shell.
*/
void	_env_(char **argv)
{
	while (*argv)
	{
		printf("%s\n", *argv);
		argv++;
	}
}
