/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_execute.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 18:38:43 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <unistd.h>

char	**get_paths(void)
{
	char	*path;
	char	**paths;

	paths = ft_split(path, ':');
	if (!paths)
	{
		printf("Failed to split PATH into PATHS, terminating program.\n");
		exit(0);
	}
	return (paths);
}

char	*ft_pathcombine(char *base, char *file)
{
	char	*path;
	int		i;

	path = malloc(ft_strlen(base) + ft_strlen(file) + 2);
	if (!path)
		exit(0);
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
	execv(*tokens, tokens);
}

void	exec_rel(char **tokens)
{
	char	*path;
	char	**paths;

	path = getenv("PATH");
	if (!path)
		path = "";
	paths = ft_split(path, ':');
	while (*paths)
	{
		path = ft_pathcombine(*paths, *tokens);
		// printf("Path: %s\n", path);
		execv(path, tokens);
		paths++;
	}
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

void	distr_input(char **tokens)
{
	pid_t	pid;
	void	(*f)(char **argv);

	f = get_builtin(*tokens);
	if (f)
	{
		f(tokens);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (ft_strcontains(*tokens, '/'))
			exec_abs(tokens);
		else
			exec_rel(tokens);
		printf("%s: command not found\n", *tokens);
	}
}

void	loop(t_shell *shell)
{
	char	input[1000];
	char	**tokens;
	int		readc;

	while (1)
	{
		readc = read(0, input, 1000);
		input[readc - 1] = 0;
		tokens = ft_split(input, ' ');
		if (!tokens || !*tokens)
			continue ;
		distr_input(tokens);
	}
}

int	main(int argc, char **args, char **env)
{
	t_shell	shell;

	shell.env = env;
	loop(&shell);
}
