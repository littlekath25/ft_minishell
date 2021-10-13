/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_prompt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/12 20:54:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*read_line(void)
{
	char	**env;
	char	*line;

	env = *g_shell->environ;
	line = readline("minishell> ");
	*g_shell->environ = env;
	return (line);
}

void	init_prompt(void)
{
	char	*line;

	while (1)
	{
		activate_signals();
		line = read_line();
		if (!line)
			shell_exit(err_exit);
		if (*line)
		{
			add_history(line);
			if (create_commands_list(line) == 1 && set_redirects() != -1)
			{
				if (g_shell->cmd->tokens->items[0] != NULL)
				{
					deactivate_signals();
					init_executor();
				}
			}
			free_command_and_tokens();
		}
		free(line);
	}
}
