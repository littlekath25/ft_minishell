#include "shell.h"

static char	*ft_pathcombine(char *base, char *file)
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

static void	exec_rel(char **tokens)
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

static void	st_setio(t_command *cmd)
{
	if (cmd->in_fd != STDIN_FILENO)
		dup2(cmd->in_fd, STDIN_FILENO);
	if (cmd->out_fd != STDOUT_FILENO)
		dup2(cmd->out_fd, STDOUT_FILENO);
}

static void	st_closeio(t_command *cmd)
{
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	if (cmd->out_fd != STDOUT_FILENO)
		close(cmd->out_fd);
}

int	exec_bin(t_command *cmd)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		shell_exit(err_fork);
	else if (pid == 0)
	{
		if (cmd->close_fd != -1)
			close(cmd->close_fd);
		st_setio(cmd);
		if (ft_strcontains(*cmd->tokens->items, '/'))
			execve(*cmd->tokens->items, cmd->tokens->items, *g_shell->environ);
		else
			exec_rel(cmd->tokens->items);
		printf("%s: command not found\n", *cmd->tokens->items);
		exit(COMMAND_NOT_FOUND);
	}
	st_closeio(cmd);
	return (pid);
}
