/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 11:02:23 by katherine     #+#    #+#                 */
/*   Updated: 2021/10/08 20:04:57 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	free_pipes(void)
{	
	int			i;
	t_command	*ptr;

	while (g_shell->cmd->pipe != NULL)
	{
		i = 0;
		ptr = g_shell->cmd->pipe->pipe;
		while (g_shell->cmd->pipe->tokens->items[i])
		{
			free(g_shell->cmd->pipe->tokens->items[i]);
			i++;
		}
		free(g_shell->cmd->pipe->tokens->items);
		free(g_shell->cmd->pipe->tokens);
		free(g_shell->cmd->pipe);
		g_shell->cmd->pipe = ptr;
	}
}

static void	free_command(void)
{
	int	i;

	i = 0;
	while (g_shell->cmd->tokens->items[i])
	{
		free(g_shell->cmd->tokens->items[i]);
		i++;
	}
	free(g_shell->cmd->tokens->items);
	free(g_shell->cmd->tokens);
	free(g_shell->cmd);
	g_shell->cmd = NULL;
}

void	free_command_and_tokens(void)
{
	if (g_shell->cmd->pipe != NULL)
		free_pipes();
	if (g_shell->cmd->tokens != NULL)
		free_command();
	free(g_shell->info->buffer);
	free(g_shell->info);
}
