/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:34:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/06 16:43:50 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	set_output(t_command *command, int i)
{
	int	fd;

	fd = open(command->tokens->items[i + 1], O_RDWR | O_CREAT, 0666);
	if (fd == -1)
		printf("%s\n", strerror(errno));
	else
	{
		command->out_fd = fd;
		delete_redirect_token(command->tokens->items, i);
		delete_redirect_token(command->tokens->items, i);
	}
}

static void	set_input(t_command *command, int i)
{
	int	fd;

	if (command->append)
		fd = open(command->tokens->items[i + 1], O_RDONLY | O_APPEND);
	else
		fd = open(command->tokens->items[i + 1], O_RDONLY | O_APPEND);
	if (fd == -1)
		printf("%s\n", strerror(errno));
	else
	{
		command->in_fd = fd;
		delete_redirect_token(command->tokens->items, i);
		delete_redirect_token(command->tokens->items, i);
	}
	command->append = 0;
}

static int	choose_redirect(t_command *command, char *line, int i)
{
	if (!(ft_strcmp(line, "<<")))
		set_delimiter(command, i);
	else if (!(ft_strcmp(line, "<")))
	{
		set_input(command, i);
		return (1);
	}
	else if (!(ft_strcmp(line, ">")) || !(ft_strcmp(line, ">>")))
	{
		if (!(ft_strcmp(line, ">>")))
			command->append = 1;
		set_output(command, i);
		return (1);
	}
	return (0);
}

void	set_redirects(void)
{
	t_command	*cmd_ptr;
	int			i;

	cmd_ptr = g_shell->cmd;
	while (cmd_ptr->pipe)
	{
		printf("HELLO PIPE\n");
		cmd_ptr = cmd_ptr->pipe;
	}
}
