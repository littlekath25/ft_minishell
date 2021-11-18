/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:05:41 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/17 20:10:57 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_parsing	*create_new_info(char *line)
{
	t_parsing	*new;

	new = (t_parsing *)ft_calloc(sizeof(t_parsing), 1);
	if (!new)
		shell_exit(err_malloc);
	new->ptr = line;
	new->state = DULL;
	new->size = BUFFER;
	new->buffer = (char *)ft_calloc(sizeof(char), BUFFER + 1);
	if (!new->buffer)
		shell_exit(err_malloc);
	g_shell->info = new;
	return (new);
}

static t_tokens	*create_new_token(void)
{
	t_tokens	*new;

	new = (t_tokens *)ft_calloc(1, sizeof(t_tokens));
	if (!new)
		shell_exit(err_malloc);
	new->size = 0;
	new->allocated = 1;
	new->items = (char **)ft_calloc(new->allocated, sizeof(char *));
	if (!new->items)
		shell_exit(err_malloc);
	return (new);
}

static t_command	*create_new_command(void)
{
	t_command	*new;

	new = (t_command *)ft_calloc(1, sizeof(t_command));
	if (new == NULL)
		shell_exit(err_malloc);
	new->pipe = NULL;
	new->tokens = NULL;
	new->in_fd = 0;
	new->out_fd = 1;
	new->unused_fd = -1;
	return (new);
}

void	create_new_command_and_tokens(t_command **dest)
{
	t_command	*new_command;
	t_tokens	*new_token;

	new_command = create_new_command();
	new_token = create_new_token();
	new_command->tokens = new_token;
	*dest = new_command;
}

t_bool	create_commands_list(char *line)
{
	t_parsing	*info;

	info = create_new_info(line);
	create_new_command_and_tokens(&g_shell->cmd);
	info->current_cmd = g_shell->cmd;
	return (fill_in_tokens(info));
}
