/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_prompt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/31 12:49:22 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_prompt(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		if (line && *line)
		{
			add_history(line);
			create_commands_list(line);
			set_redirects();
			// print_tokens();
			init_executor();
			free_command_and_tokens();
		}
		free(line);
	}
}
