/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 11:06:03 by katherine     #+#    #+#                 */
/*   Updated: 2021/07/27 21:40:28 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	set_output(t_command *command, int i)
{
	int	fd;

	fd = open(command->tokens->items[i + 1], O_RDWR | O_CREAT, 0666);
	printf("FD: %i\n", fd);
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

void	set_input_output(t_command *command)
{
	int	i;

	i = 0;
	while (command->tokens->items[i])
	{
		if (!(ft_strcmp(command->tokens->items[i], ">>")))
		{
			command->append = 1;
			set_output(command, i);
			continue ;
		}
		else if (!(ft_strcmp(command->tokens->items[i], "<")))
		{
			set_input(command, i);
			continue ;
		}
		else if (!(ft_strcmp(command->tokens->items[i], ">")))
		{
			set_output(command, i);
			continue ;
		}
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
			set_input_output(ptr);
			ptr = ptr->next;
		}
	}
	if (g_shell->cmd != NULL)
		set_input_output(g_shell->cmd);
}
