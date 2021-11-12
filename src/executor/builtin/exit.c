/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:48:13 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/11 11:20:03 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdlib.h>

static t_bool	str_isdigit(char *str)
{
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

/* conclusion:
	if the first arg is non-numerical, print numeric required and exit 255
	else if more than one argument, don't exit, set shell error statuscode.
*/
int	_exit_(char **argv)
{
	if (g_shell->io_fds[0] != STDIN_FILENO || \
		g_shell->io_fds[1] != STDOUT_FILENO)
		return (0);
	printf("exit\n");
	if (argv[1])
	{
		if (!str_isdigit(argv[1]))
		{
			printf("minishell: %s: numeric argument required\n", argv[1]);
			exit(255);
		}
		else
		{
			if (argv[2])
			{
				printf("minishell: %s: too many arguments\n", argv[0]);
				return (1);
			}
			exit(ft_atoi(argv[1]));
		}
	}
	exit(0);
	return (0);
}
