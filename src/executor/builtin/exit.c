/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:48:13 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/01 21:51:08 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

void	_exit_(char **argv)
{
	free_command_and_tokens();
	(void)argv;
	exit(0);
}
