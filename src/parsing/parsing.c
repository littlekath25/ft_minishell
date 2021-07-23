/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/23 13:43:33 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free_pipes(void)
{	
	int			i;
	t_command	*ptr;

	while (g_shell->commands->pipe != NULL)
	{
		i = 0;
		ptr = g_shell->commands->pipe->next;
		while (g_shell->commands->pipe->tokens->items[i])
		{
			free(g_shell->commands->pipe->tokens->items[i]);
			i++;
		}
		free(g_shell->commands->pipe->tokens->items);
		free(g_shell->commands->pipe->tokens);
		free(g_shell->commands->pipe);
		g_shell->commands->pipe = ptr;
	}
}

void	free_command(void)
{
	int	i;

	i = 0;
	while (g_shell->commands->tokens->items[i])
	{
		free(g_shell->commands->tokens->items[i]);
		i++;
	}
	free(g_shell->commands->tokens->items);
	free(g_shell->commands->tokens);
	free(g_shell->commands);
	g_shell->commands = NULL;
}

void	free_command_and_tokens(void)
{
	if (g_shell->commands->pipe != NULL)
		free_pipes();
	if (g_shell->commands->tokens != NULL)
		free_command();
}

void	read_commands(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		if (line && *line)
		{
			if (!ft_strcmp(line, "exit"))
				break ;
			add_history(line);
			create_commands_list(line);
			print_tokens();
			free_command_and_tokens();
		}
		free(line);
	}
}
