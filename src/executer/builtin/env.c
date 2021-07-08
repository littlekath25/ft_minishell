/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:04:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 15:07:01 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../../includes/shell.h"

/*
	Print env.
	Env is loaded on startup and is stored in t_shell.
*/
void	_env_(char **argv)
{
	char	**env;

	env = g_shell->env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
