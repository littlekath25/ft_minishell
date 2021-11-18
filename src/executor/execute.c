/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/17 20:20:26 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

static void	st_create_pipe(t_command *cmd)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		shell_exit(err_pipe);
	cmd->pipe->in_fd = pipefd[0];
	cmd->pipe->unused_fd = pipefd[1];
	cmd->unused_fd = pipefd[0];
	cmd->out_fd = pipefd[1];
}

static void	st_exec_builtin(t_command *cmd, int (*f)(char **argv))
{
	if (handle_redirects(cmd) == false)
	{
		close_non_stdio(cmd);
		return ;
	}
	g_shell->io_fds[0] = cmd->in_fd;
	g_shell->io_fds[1] = cmd->out_fd;
	g_shell->returnstatus = f(cmd->tokens->items);
	if (g_shell->io_fds[1] != STDOUT_FILENO)
	{
		close(g_shell->io_fds[1]);
		g_shell->io_fds[1] = STDOUT_FILENO;
	}
	if (g_shell->io_fds[0] != STDIN_FILENO)
	{
		close(g_shell->io_fds[0]);
		g_shell->io_fds[0] = STDIN_FILENO;
	}
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
	int			forks[FORK_MAX];
	int			retval;
	int			i;
	int			j;

	cmd_list = g_shell->cmd;
	i = 0;
	j = 0;
	while (cmd_list && j < FORK_MAX)
	{
		retval = st_distribute(cmd_list);
		if (retval != -1)
		{
			forks[i] = retval;
			i++;
		}
		cmd_list = cmd_list->pipe;
		j++;
	}
	if (j == FORK_MAX)
		ft_putstr_fd("minishell: maximum amount of forks\n", STDOUT_FILENO);
	wait_pids(forks, i);
	unlink(HEREDOC_FNAME);
}
