/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:04:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/04 14:28:14 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../../includes/shell.h"

/*
	Prints all environment variables in environment variables list.
	This means key-value paired variabled.
*/
void	_env_(char **argv)
{
	char	**env;

	(void)argv;
	env = *g_shell->environ;
	if (!env)
		return ;
	while (*env)
	{
		if (ft_strchr(*env, '='))
			printf("%s\n", *env);
		env++;
	}
}
