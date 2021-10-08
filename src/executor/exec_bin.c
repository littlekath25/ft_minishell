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

static void	exec_abs(char **tokens)
{
	execve(*tokens, tokens, *g_shell->environ);
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

void	exec_bin(t_command *cmd)
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
		wait_and_set_returnvalue(pid);
		if (cmd->out_fd != STDOUT_FILENO)
			close(cmd->out_fd);
	}
}
