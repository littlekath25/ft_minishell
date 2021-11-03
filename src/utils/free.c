/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 11:02:23 by katherine     #+#    #+#                 */
/*   Updated: 2021/11/03 11:47:58 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	free_command(t_command *cmd)
{
	t_heredoc	*tmp;

	ft_free_split(cmd->tokens->items);
	free(cmd->tokens);
	while (g_shell->heredocs)
	{
		tmp = g_shell->heredocs;
		g_shell->heredocs = g_shell->heredocs->next;
		free(tmp->delimiter);
		free(tmp);
	}
	free(cmd);
}

void	free_command_and_tokens(void)
{
	t_command	*cmd;

	cmd = g_shell->cmd;
	while (cmd)
	{
		free_command(cmd);
		cmd = cmd->pipe;
	}
	free(g_shell->info->buffer);
	free(g_shell->info);
}
