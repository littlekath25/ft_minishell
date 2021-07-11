/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/11 16:17:54 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	main(int argc, char **argv, char **env)
{
	if (argc == 1 && argv[0])
	{
		g_shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
		if (g_shell == NULL)
			error_and_exit(2);
		g_shell->env = env;
		read_commands();
		exit(0);
	}
	else
		error_and_exit(1);
	return (0);
}
