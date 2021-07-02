/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 12:16:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/02 12:31:58 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_command(t_command *new)
{
	new->pipe = NULL;
	new->tokens = NULL;
	new->in_fd = 0;
	new->out_fd = 1;
	new->previous = NULL;
	new->next = NULL;
}

void	add_back_command(t_shell *shell, t_command *new)
{
	t_command	*ptr;

	if (shell->commands == NULL)
		shell->commands = new;
	else
	{
		ptr = shell->commands;
		while (ptr != NULL)
			ptr = ptr->next;
		ptr = new;
	}
}

void	add_new_command(char *line, t_shell *shell)
{
	t_command	*new;
	t_command	*ptr;

	new = (t_command *)ft_calloc(1, sizeof(t_command));
	init_command(new);
	add_back_command(shell, new);
}
