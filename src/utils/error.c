/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 16:42:28 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/13 16:42:03 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_exit(int error)
{
	if (error == err_args)
		printf("Please execute without arguments\n");
	if (error == err_malloc)
		printf("Malloc failed\n");
	if (error == err_pipe)
		printf("Pipe failed\n");
	if (error == err_fork)
		printf("Fork failed\n");
	if (error == err_exit)
		printf("exit\n");
	exit(0);
}
