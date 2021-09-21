/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 11:06:03 by katherine     #+#    #+#                 */
/*   Updated: 2021/09/21 19:57:46 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	set_output(t_command *command, int i)
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

void	set_input(t_command *command, int i)
{
	int	fd;

	fd = open(command->tokens->items[i + 1], O_RDONLY);
	if (fd == -1)
		printf("%s\n", strerror(errno));
	else
	{
		command->in_fd = fd;
		delete_redirect_token(command->tokens->items, i);
		delete_redirect_token(command->tokens->items, i);
	}
}

void	set_delimiter(t_command *command, int i)
{
	command->delimiter = ft_strdup(command->tokens->items[i + 1]);
	delete_redirect_token(command->tokens->items, i);
	delete_redirect_token(command->tokens->items, i);
}

int	choose_redirect(t_command *command, char *line, int i)
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
	else if (!(ft_strncmp(line, "'$", 2)) || line[0] == '"' || line[0] == '\'')
		remove_unnecessary_quotes(command, i);
	else if (line[0] == '$')
		printf("envvar: %s\n", process_variable(&line));
	return (0);
}

void	set_redirects(void)
{
	t_command	*ptr;

	if (g_shell->cmd->pipe != NULL)
	{
		ptr = g_shell->cmd->pipe;
		clean_up_tokens(ptr);
	}
	if (g_shell->cmd != NULL)
		clean_up_tokens(g_shell->cmd);
}
