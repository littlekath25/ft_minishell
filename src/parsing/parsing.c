/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/02 17:37:11 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	read_commands(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		create_commands_list(line, shell);
		if (!ft_strcmp(line, "exit"))
			break ;
		free(line);
	}
}

