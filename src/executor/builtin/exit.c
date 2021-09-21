/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:48:13 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/21 16:21:40 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

int	_exit_(char **argv)
{
	(void)argv;
	exit(0);
	return (0);
}
