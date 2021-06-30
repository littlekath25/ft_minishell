/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/29 17:45:17 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	add_command(char *line, t_shell *shell)
{
	t_tree		*tree;
	t_command	*new;
	t_command	*ptr;

	tree = (t_tree *)ft_calloc(1, sizeof(t_tree));
	new = (t_command *)ft_calloc(1, sizeof(t_command));
	ptr = tree->commands;
	while (ptr != NULL)
		ptr = tree->commands->next;
	new->command = line;
	ptr->next = new;
}

void	read_from_stdin(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		add_command(line, shell);
		free(line);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	if (argc == 1 && argv[0])
	{
		shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
		shell->env = env;
		read_from_stdin(shell);
		exit(0);
	}
	else
		error_and_exit(1);
}
 