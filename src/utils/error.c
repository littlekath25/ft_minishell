/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 16:42:28 by kfu           #+#    #+#                 */
/*   Updated: 2021/08/09 13:22:16 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	print_tokens(void)
{
	int i = 0;
	int	j = 0;
	t_command	*ptr;
	t_command	*command_ptr;

	command_ptr = g_shell->cmd;
	if (command_ptr)
	{
		i = 0;
		while (command_ptr->tokens->items[i])
		{
			printf("LINE %i: %s\n", j, command_ptr->tokens->items[i]);
			i++;
		}
		j++;
	}
	i = 0;
	ptr = g_shell->cmd->pipe;
	if (ptr)
	{
		while (ptr != NULL)
		{
			i = 0;
			while (g_shell->cmd->pipe->tokens->items[i])
			{
				printf("PIPE %i: %s\n",j, ptr->tokens->items[i]);
				i++;
			}
			j++;
			ptr = ptr->next;
		}
	}
}

void	shell_exit(int error)
{
	if (error == err_args)
		printf("Please execute without arguments\n");
	if (error == err_malloc)
		printf("Malloc failed\n");
	if (error == err_pipe)
		printf("Pipe failed\n");
	if (error == err_fork)
		printf("Fork failed\n");
	exit(0);
}
