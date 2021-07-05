/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/05 10:21:45 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_from_stdin(t_shell *shell)
{
	char	*line;
	char	**split;

	while (1)
	{
		line = readline("minishell> ");
		split = ft_split(line, ' ');
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
		if (shell == NULL)
			error_and_exit(2);
		shell->env = env;
		read_commands(shell);
		exit(0);
	}
	else
		error_and_exit(1);
	return (0);
}
 