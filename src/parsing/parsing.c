/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/19 15:05:44 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	read_commands(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		if (line && *line)
		{
			add_history(line);
			create_commands_list(line);
			print_tokens();
			if (!ft_strcmp(line, "exit"))
				break ;
		}
		free(line);
	}
}

t_parsing	*create_new_info(char *line)
{
	t_parsing	*new;

	new = (t_parsing *)ft_calloc(sizeof(t_parsing), 1);
	if (!new)
		error_and_exit(2);
	new->ptr = line;
	new->start = NULL;
	new->argc = 0;
	new->state = DULL;
	return (new);
}

t_command	*create_new_command_and_tokens(t_command **dest)
{
	t_command	*new_command;
	t_tokens	*new_token;

	new_command = create_new_command();
	new_token = create_new_token();
	new_command->tokens = new_token;
	add_back_command(dest, new_command);
	return (new_command);
}

void	create_commands_list(char *line)
{
	t_parsing	*info;
	t_command	**dest;

	info = create_new_info(line);
	while (info->state != DONE)
	{
		if (info->state == DONE)
			break ;
		else if (info->state == DULL)
			dest = &g_shell->commands;
		else if (info->state == IN_PIPE)
		{
			info->argc = 0;
			dest = &g_shell->commands->pipe;
		}
		fill_in_tokens(info, create_new_command_and_tokens(dest)->tokens);
	}
}
