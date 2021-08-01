/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 11:06:03 by katherine     #+#    #+#                 */
/*   Updated: 2021/08/01 13:42:39 by kfu           ########   odam.nl         */
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

void	clean_up_tokens(t_command *command)
{
	int	i;

	i = 0;
	while (command->tokens->items[i])
	{
		if (ft_strchr(command->tokens->items[i], '='))
			command->tokens->items[i] = \
			delete_all_quotes(command->tokens->items[i]);
		else if (!(ft_strcmp(command->tokens->items[i], "<<")))
			set_delimiter(command, i);
		else if (!(ft_strcmp(command->tokens->items[i], "<")))
		{
			set_input(command, i);
			continue ;
		}
		else if (!(ft_strcmp(command->tokens->items[i], ">")) \
		|| !(ft_strcmp(command->tokens->items[i], ">>")))
		{
			if (!(ft_strcmp(command->tokens->items[i], ">>")))
				command->append = 1;
			set_output(command, i);
			continue ;
		}
		else if (command->tokens->items[i][0] == '$')
			convert_arg(command, i);
		i++;
	}
}

void	set_redirects(void)
{
	t_command	*ptr;

	if (g_shell->cmd->pipe != NULL)
	{
		ptr = g_shell->cmd->pipe;
		while (ptr != NULL)
		{
			clean_up_tokens(ptr);
			ptr = ptr->next;
		}
	}
	if (g_shell->cmd != NULL)
		clean_up_tokens(g_shell->cmd);
}
