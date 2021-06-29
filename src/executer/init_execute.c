/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_execute.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/29 15:59:49 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <unistd.h>

void	init_execute(t_tree *trees)
{
	
}

char	*get_envvar(char **env, char *key)
{
	int	len;

	len = ft_strlen(key);
	while (*env)
	{
		if (!ft_memcmp(*env, key, len))
		{
			if (*(*env + len) == '=')
				return (*env + len + 1);
		}
		env++;
	}
	return (0);
}

char	**get_paths(char **env)
{
	char	*path;
	char	**paths;

	path = get_envvar(env, "PATH");
	if (!path)
	{
		printf("Failed to fetch PATH, terminating program.\n");
		exit(0);
	}
	paths = ft_split(path, ':');
	if (!paths)
	{
		printf("Failed to split PATH into PATHS, terminating program.\n");
		exit(0);
	}
	return (paths);
}

void	ft_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

void	ft_strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

char	*path_combine(char *base, char *execname)
{
	char	*path;
	int		baselen;
	int		execnamelen;

	baselen = ft_strlen(base);
	execnamelen = ft_strlen(execname);
	path = malloc(baselen + execnamelen + 2);
	if (!path)
		exit(0);
	ft_strcpy(path, base);
	ft_strcat(path, "/");
	ft_strcat(path, execname);
	return (path);
}

void	execute(char **paths, char *name)
{
	char	*argv[2];
	char	*path;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		argv[0] = name;
		argv[1] = 0;
		while (*paths)
		{
			path = path_combine(*paths, name);
			// printf("Path: %s\n", path);
			execv(path, argv);
			paths++;
		}
		printf("%s: command not found\n", name);
	}
}

void	loop(t_shell *shell)
{
	char	input[10000];
	int		readc;

	while (1)
	{
		readc = read(0, input, 10000);
		input[readc - 1] = 0;
		execute(shell->paths, input);
	}
}

int	main(int argc, char **args, char **env)
{
	t_shell	shell;

	shell.env = env;
	shell.paths = get_paths(env);
	loop(&shell);
}
