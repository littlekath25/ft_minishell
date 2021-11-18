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

static void	exec_absolute_path(t_command *cmd)
{
	execve(*cmd->tokens->items, cmd->tokens->items, *g_shell->environ);
	print_perror(cmd->tokens->items[0]);
	if (errno == EACCES)
		exit(CANNOT_EXECUTE);
	else if (errno == ENOENT)
		exit(COMMAND_NOT_FOUND);
	exit(1);
}

static void	exec_relative_path(char **tokens)
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
	ft_putstr_fd("minishell: ", STDOUT_FILENO);
	ft_putstr_fd(*tokens, STDOUT_FILENO);
	ft_putstr_fd(": command not found\n", STDOUT_FILENO);
	exit(COMMAND_NOT_FOUND);
}

static void	st_setio(t_command *cmd)
{
	if (cmd->in_fd != STDIN_FILENO)
		dup2(cmd->in_fd, STDIN_FILENO);
	if (cmd->out_fd != STDOUT_FILENO)
		dup2(cmd->out_fd, STDOUT_FILENO);
}

int	exec_bin(t_command *cmd)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		shell_exit(err_fork);
	else if (pid == 0)
	{
		close_unused_fd(cmd);
		if (handle_redirects(cmd) == false)
			exit(1);
		st_setio(cmd);
		if (ft_strcontains(*cmd->tokens->items, '/'))
			exec_absolute_path(cmd);
		else
			exec_relative_path(cmd->tokens->items);
	}
	close_non_stdio(cmd);
	return (pid);
}
