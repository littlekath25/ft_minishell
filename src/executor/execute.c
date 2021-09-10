/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/10 12:03:51 by kfu           ########   odam.nl         */
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

static void	st_create_pipe(t_command *cmd, int pipefd[2])
{
	// int		pipefd[2];

	// if (pipe(pipefd) == -1)
		// shell_exit(err_pipe);
	cmd->pipe->in_fd = pipefd[0];
	cmd->out_fd = pipefd[1];
	printf("read end pipefd[0] = %d\nwrite end pipefd[1] = %d\n", pipefd[0], pipefd[1]);
}

static void	st_setio(t_command *cmd)
{
	if (cmd->in_fd != STDIN_FILENO)
	{
		printf("Overwriting IN_FD (%s) (%d to %d)\n", *cmd->tokens->items, STDIN_FILENO, cmd->in_fd);
		dup2(cmd->in_fd, STDIN_FILENO);
	}
	if (cmd->out_fd != STDOUT_FILENO)
	{
		printf("Overwriting OUT_FD (%s) (%d to %d)\n", *cmd->tokens->items, STDOUT_FILENO, cmd->out_fd);
		dup2(cmd->out_fd, STDOUT_FILENO);
	}
}

static void	st_bin(t_command *cmd)
{
	int		pid;
	int		status;
	int		pipefd[2];

	if (cmd->pipe)
	{
		if (pipe(pipefd) == -1)
			shell_exit(err_pipe);
		st_create_pipe(cmd, pipefd);
	}
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
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(pipefd[1]);
	}
}

static void	st_distribute(t_command *cmd)
{
	void	(*f)(char **argv);

	f = get_builtin(*cmd->tokens->items);
	if (f)
		f(cmd->tokens->items);
	else
		st_bin(cmd);
}

void	init_executor(void)
{
	t_command	*cmd_list;
	t_command	*cmd_pipe;

	cmd_list = g_shell->cmd;
	while (cmd_list)
	{
		cmd_pipe = cmd_list;
		while (cmd_pipe)
		{
			st_distribute(cmd_pipe);
			cmd_pipe = cmd_pipe->pipe;
		}
		cmd_list = cmd_list->pipe;
	}
}
