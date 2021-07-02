/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/02 13:27:43 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	read_commands(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		add_new_command(line, shell);
		if (!ft_strcmp(line, "exit"))
			break;
		free(line);
	}
	print_token();
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
	return (0);
}
 