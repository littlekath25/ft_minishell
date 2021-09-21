/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/21 16:45:19 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../includes/libft.h"
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_pathcombine(char *base, char *file)
{
	char	*path;
	int		i;

	path = malloc(ft_strlen(base) + ft_strlen(file) + 2);
	if (!path)
		shell_exit(err_malloc);
	i = 0;
	while (base[i])
	{
		path[i] = base[i];
		i++;
	}
	path[i] = '/';
	i++;
	while (*file)
	{
		path[i] = *file;
		file++;
		i++;
	}
	path[i] = 0;
	return (path);
}

void	exec_abs(char **tokens)
{
	execve(*tokens, tokens, *g_shell->environ);
}

void	exec_rel(char **tokens)
{
	char	*path;
	char	**paths;
	int		i;

	path = getenv("PATH");
	if (!path)
		path = "";
	paths = ft_split(path, ':');
	if (!paths)
		shell_exit(err_malloc);
	i = 0;
	while (paths[i])
	{
		path = ft_pathcombine(paths[i], *tokens);
		execve(path, tokens, *g_shell->environ);
		free(path);
		i++;
	}
	ft_free_split(paths);
}

char	ft_strcontains(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static void	st_setio(t_command *cmd)
{
	if (cmd->in_fd != STDIN_FILENO)
	{
		// printf("Overwriting IN_FD (%s) (%d to %d)\n", *cmd->tokens->items, STDIN_FILENO, cmd->in_fd);
		dup2(cmd->in_fd, STDIN_FILENO);
	}
	if (cmd->out_fd != STDOUT_FILENO)
	{
		// printf("Overwriting OUT_FD (%s) (%d to %d)\n", *cmd->tokens->items, STDOUT_FILENO, cmd->out_fd);
		dup2(cmd->out_fd, STDOUT_FILENO);
	}
}

static int	get_exit_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	 else if (WIFSIGNALED(wstatus))
	 	return (128 + WTERMSIG(wstatus));
	else if (WIFSTOPPED(wstatus))
		return (WSTOPSIG(wstatus));
	return (-1);
}

static void	st_wait_and_set_returnvalue(int pid)
{
	int		status;

	if (waitpid(pid, &status, 0) != -1)
	{
		g_shell->returnstatus = get_exit_code(status);
	}
	else
	{
		// couldn't wait for pid
		printf("ERROR: Couldn't wait for pid\n");
	}
}

static void	st_exec_bin(t_command *cmd)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		shell_exit(err_fork);
	else if (pid == 0)
	{
		st_setio(cmd);
		if (ft_strcontains(*cmd->tokens->items, '/'))
			exec_abs(cmd->tokens->items);
		else
			exec_rel(cmd->tokens->items);
		printf("%s: command not found\n", *cmd->tokens->items);
		exit(COMMAND_NOT_FOUND);
	}
	else
	{
		st_wait_and_set_returnvalue(pid);
		if (cmd->out_fd != STDOUT_FILENO)
			close(cmd->out_fd);
	}
}

static void	st_create_pipe(t_command *cmd)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		shell_exit(err_pipe);
	cmd->pipe->in_fd = pipefd[0];
	cmd->out_fd = pipefd[1];
}

static void	st_exec_builtin(t_command *cmd, int (*f)(char **argv))
{
	g_shell->io_fds[0] = cmd->in_fd;
	g_shell->io_fds[1] = cmd->out_fd;
	g_shell->returnstatus = f(cmd->tokens->items);
	if (cmd->out_fd != STDOUT_FILENO)
		close(cmd->out_fd);
	g_shell->io_fds[0] = STDIN_FILENO;
	g_shell->io_fds[1] = STDOUT_FILENO;
}

static void	st_distribute(t_command *cmd)
{
	int	(*f)(char **argv);

	if (cmd->pipe)
		st_create_pipe(cmd);
	f = get_builtin(*cmd->tokens->items);
	if (f != NULL)
		st_exec_builtin(cmd, f);
	else
		st_exec_bin(cmd);
}

void	init_executor(void)
{
	t_command	*cmd_list;

	cmd_list = g_shell->cmd;
	while (cmd_list)
	{
		st_distribute(cmd_list);
		cmd_list = cmd_list->pipe;
	}
}
