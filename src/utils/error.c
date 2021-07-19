/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 16:42:28 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/19 11:51:54 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	print_tokens(void)
{
	int i = 0;
	int	j = 0;
	t_command *ptr;

	if (g_shell->commands)
	{
		while (g_shell->commands->tokens->items[i])
		{
			printf("LINE: %s\n", g_shell->commands->tokens->items[i]);
			i++;
		}
	}
	i = 0;
	ptr = g_shell->commands->pipe;
	if (ptr)
	{
		while (ptr != NULL)
		{
			i = 0;
			while (g_shell->commands->pipe->tokens->items[i])
			{
				printf("PIPE %i: %s\n",j, ptr->tokens->items[i]);
				i++;
			}
			j++;
			ptr = ptr->next;
		}
	}
}

void	error_and_exit(int error)
{
	if (error == 1)
		printf("Please execute without arguments\n");
	if (error == 2)
		printf("Malloc fail\n");
	exit(0);
}
