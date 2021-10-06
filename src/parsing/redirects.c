/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:34:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/06 18:43:47 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	delete_redirect_token(char **pointers, int i)
{
	free(pointers[i]);
	while (pointers[i + 1] != NULL)
	{
		pointers[i] = pointers[i + 1];
		i++;
	}
	pointers[i] = NULL;
}

static void	set_output(t_command *command, int i)
{
	int	fd;

	if (command->append)
		fd = open(command->tokens->items[i + 1], O_RDWR | O_CREAT | O_APPEND, 0666);
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
	if (!(ft_strcmp(line, "<<")))
		printf("DELIMITER\n");
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
	char		*token;
	int			i;

	i = 0;
	cmd_ptr = g_shell->cmd;
	while (cmd_ptr)
	{
		i = 0;
		token = cmd_ptr->tokens->items[i];
		while (token)
		{
			if (!choose_redirect(cmd_ptr, token, i))
				i++;
			token = cmd_ptr->tokens->items[i];
		}
		cmd_ptr = cmd_ptr->pipe;
	}
}
