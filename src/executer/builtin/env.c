/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:04:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/29 17:33:59 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	env(char **env)
{
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
