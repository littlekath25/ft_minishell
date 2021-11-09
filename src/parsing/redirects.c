/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:34:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/03 14:54:36 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	set_delimiter(t_command *cmd, int i)
{
	char	*dlmtr_dup;

	dlmtr_dup = ft_strdup(cmd->tokens->items[i + 1]);
	if (!dlmtr_dup)
		shell_exit(err_malloc);
	heredoc_addnew(dlmtr_dup);
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	cmd->in_fd = STDIN_FILENO;
	clean_up_tokens(cmd->tokens->items, i);
	return (1);
}

static int	set_output(t_command *cmd, int i)
{
	int	fd;

	if (cmd->append)
		fd = open(cmd->tokens->items[i + 1], \
		O_RDWR | O_CREAT | O_APPEND, 0666);
	else
		fd = open(cmd->tokens->items[i + 1], \
		O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		printf("%s: %s\n", cmd->tokens->items[i + 1], strerror(errno));
		return (-1);
	}
	else
		cmd->out_fd = fd;
	clean_up_tokens(cmd->tokens->items, i);
	return (1);
}

static int	set_input(t_command *cmd, int i)
{
	int	fd;

	fd = open(cmd->tokens->items[i + 1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s: %s\n", cmd->tokens->items[i + 1], strerror(errno));
		return (-1);
	}
	else
		cmd->in_fd = fd;
	clean_up_tokens(cmd->tokens->items, i);
	cmd->append = 0;
	return (1);
}

static int	choose_redirect(t_command *cmd, char *line, int i)
{
	t_redirects	redirect;
	int			ret;

	ret = 0;
	redirect = which_redirect(line);
	if (redirect && i == 0)
	{
		print_error_token(*line);
		return (-1);
	}
	else if (redirect == INPUT)
		ret = set_input(cmd, i);
	else if (redirect == OUTPUT || redirect == APPEND)
	{
		if (redirect == APPEND)
			cmd->append = 1;
		ret = set_output(cmd, i);
	}
	else if (redirect == DELIMITER)
		ret = set_delimiter(cmd, i);
	return (ret);
}

int	iterate_tokens(int ret, char *token)
{
	t_command	*cmd_ptr;
	int			i;

	cmd_ptr = g_shell->cmd;
	while (cmd_ptr)
	{
		i = 0;
		token = cmd_ptr->tokens->items[i];
		while (token)
		{
			ret = choose_redirect(cmd_ptr, token, i);
			if (ret == 1)
			{
				token = cmd_ptr->tokens->items[i];
				continue ;
			}
			else if (ret == -1)
				return (-1);
			i++;
			token = cmd_ptr->tokens->items[i];
		}
		cmd_ptr = cmd_ptr->pipe;
	}
	return (0);
}
