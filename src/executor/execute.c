/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/13 15:05:19 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

static void	st_create_pipe(t_command *cmd)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		shell_exit(err_pipe);
	cmd->pipe->in_fd = pipefd[0];
	cmd->out_fd = pipefd[1];
	cmd->close_fd = pipefd[0];
	cmd->pipe->close_fd = pipefd[1];
}

static void	st_exec_builtin(t_command *cmd, int (*f)(char **argv))
{
	if (cmd->close_fd != -1)
		close(cmd->close_fd);
	g_shell->io_fds[0] = cmd->in_fd;
	g_shell->io_fds[1] = cmd->out_fd;
	g_shell->returnstatus = f(cmd->tokens->items);
	if (cmd->out_fd != STDOUT_FILENO)
		close(cmd->out_fd);
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	g_shell->io_fds[0] = STDIN_FILENO;
	g_shell->io_fds[1] = STDOUT_FILENO;
}

static int	st_distribute(t_command *cmd)
{
	int	(*f)(char **argv);

	if (cmd->pipe)
		st_create_pipe(cmd);
	f = get_builtin(*cmd->tokens->items);
	if (f != NULL)
		st_exec_builtin(cmd, f);
	else
		return (exec_bin(cmd));
	return (-1);
}

static void	wait_pids(int forks[], int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		wait_and_set_returnvalue(forks[j]);
		j++;
	}
}

void	init_executor(void)
{
	t_command	*cmd_list;
	int			forks[1000];
	int			retval;
	int			i;

	cmd_list = g_shell->cmd;
	i = 0;
	while (cmd_list)
	{
		retval = st_distribute(cmd_list);
		if (retval != -1)
		{
			forks[i] = retval;
			i++;
		}
		cmd_list = cmd_list->pipe;
	}
	wait_pids(forks, i);
}
