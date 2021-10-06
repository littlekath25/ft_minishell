/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_prompt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/06 16:03:17 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	print_return_status(void)
{
	printf("Status: %d\n", g_shell->returnstatus);
}

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
				// print_tokens();
				init_executor();
			}
			free_command_and_tokens();
		}
		free(line);
	}
}
