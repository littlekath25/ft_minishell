/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:34:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/08 13:54:17 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	set_delimiter(t_command *command, int i)
{
	command->delimiter = ft_strdup(command->tokens->items[i + 1]);
	delete_redirect_token(command->tokens->items, i);
	delete_redirect_token(command->tokens->items, i);
}

static void	set_output(t_command *command, int i)
{
	int	fd;

	if (command->append)
		fd = open(command->tokens->items[i + 1], \
		O_RDWR | O_CREAT | O_APPEND, 0666);
	else
		fd = open(command->tokens->items[i + 1], O_RDWR | O_CREAT, 0666);
	if (fd == -1)
		printf("%s: %s\n", command->tokens->items[i + 1], strerror(errno));
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

	fd = open(command->tokens->items[i + 1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s: %s\n", command->tokens->items[i + 1], strerror(errno));
		exit(0);
	}
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
	t_redirects	redirect;

	redirect = which_redirect(line);
	if (redirect && i == 0)
	{
		print_error_token(*line);
		return (-1);
	}
	else if (redirect == INPUT)
		set_input(command, i);
	else if (redirect == OUTPUT || redirect == APPEND)
	{
		if (redirect == APPEND)
			command->append = 1;
		set_output(command, i);
	}
	else if (redirect == DELIMITER)
		set_delimiter(command, i);
	else
		return (0);
	return (1);
}

int	set_redirects(void)
{
	t_command	*cmd_ptr;
	char		*token;
	int			i;
	int			ret;

	i = 0;
	cmd_ptr = g_shell->cmd;
	while (cmd_ptr)
	{
		i = 0;
		token = cmd_ptr->tokens->items[i];
		while (token)
		{
			ret = choose_redirect(cmd_ptr, token, i);
			if (ret == 0)
				i++;
			else if (ret == -1)
				return (-1);
			token = cmd_ptr->tokens->items[i];
		}
		cmd_ptr = cmd_ptr->pipe;
	}
	return (0);
}
