/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 12:16:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/08/09 11:22:41 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_command(t_command *new)
{
	new->pipe = NULL;
	new->tokens = NULL;
	new->in_fd = 0;
	new->out_fd = 1;
	new->next = NULL;
}

void	add_back_command(t_command **dest, t_command *new)
{
	t_command	*ptr;

	if (*dest == NULL)
		*dest = new;
	else
	{
		ptr = *dest;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

t_command	*create_new_command(void)
{
	t_command	*new;

	new = (t_command *)ft_calloc(1, sizeof(t_command));
	if (new == NULL)
		shell_exit(err_malloc);
	init_command(new);
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

int	create_commands_list(char *line)
{
	t_parsing	*info;
	t_command	**dest;

	info = create_new_info(line);
	while (info->state != DONE)
	{
		if (info->state == DONE || info->state == ERROR)
			break ;
		else if (info->state == DULL)
			dest = &g_shell->cmd;
		else if (info->state == IN_PIPE)
		{
			info->argc = 0;
			dest = &g_shell->cmd->pipe;
		}
		fill_in_tokens(info, create_new_command_and_tokens(dest)->tokens);
	}
	free(info);
	if (g_shell->cmd->tokens->items[0] != NULL)
		return (1);
	return (0);
}
