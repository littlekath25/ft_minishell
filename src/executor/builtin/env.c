/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:04:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/25 16:22:04 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../../includes/shell.h"

/*
	Prints environment variables list.
*/
void	_env_(char **argv)
{
	char	**env;

	(void)argv;
	env = __environ;
	if (!env)
		return ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
