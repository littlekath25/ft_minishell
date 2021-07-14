/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/14 14:11:37 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	read_commands(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		create_commands_list(line);
		if (!ft_strcmp(line, "exit"))
			break ;
		free(line);
	}
}

void	create_commands_list(char *line)
{
	t_command	*new_command;

	new_command = create_new_command();
	add_back_command(&g_shell->commands, new_command);
	new_command->tokens = create_new_token();
	fill_in_tokens(line, new_command->tokens);
}
