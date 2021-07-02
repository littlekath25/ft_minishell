/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/02 11:02:11 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	add_command(char *line, t_shell *shell)
{
	
}

void	read_commands(t_shell *shell)
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
		read_commands(shell);
		exit(0);
	}
	else
		error_and_exit(1);
}
 