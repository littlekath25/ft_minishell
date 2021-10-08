/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_prompt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/08 14:11:23 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_prompt(void)
{
	char	*line;
	char	**env;

	while (1)
	{
		env = *g_shell->environ;
		line = readline("minishell> ");
		*g_shell->environ = env;
		if (!line)
			shell_exit(err_exit);
		if (*line)
		{
			add_history(line);
			if (create_commands_list(line) == 1)
			{
				if (set_redirects() != -1)
				{
					if (g_shell->cmd->tokens->items[0] != NULL)
						init_executor();
				}
			}
			free_command_and_tokens();
		}
		free(line);
	}
}
