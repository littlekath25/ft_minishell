/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 11:02:23 by katherine     #+#    #+#                 */
/*   Updated: 2021/07/24 11:03:06 by katherine     ########   odam.nl         */
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
