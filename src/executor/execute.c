/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/01 12:49:54 by pspijkst      ########   odam.nl         */
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

static void	st_execute(char **tokens)
{
	int		pid;
	void	(*f)(char **argv);
	int		status;

	f = get_builtin(*tokens);
	if (f)
	{
		f(tokens);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (ft_strcontains(*tokens, '/'))
			exec_abs(tokens);
		else
			exec_rel(tokens);
		printf("%s: command not found\n", *tokens);
		return ;
	}
	wait(&status);
}

void	init_executor(void)
{
	t_command	*cmd;

	cmd = g_shell->cmd;
	while (cmd)
	{
		st_execute(cmd->tokens->items);
		cmd = cmd->next;
	}
}
