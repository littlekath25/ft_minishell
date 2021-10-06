/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/09 11:21:01 by katherine     #+#    #+#                 */
/*   Updated: 2021/10/06 16:02:38 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	new_pipe(t_parsing *info)
{
	info->argc = 0;
	info->i = 0;
	info->state = IN_WORD;
	copy_to_buffer(info);
	create_new_command_and_tokens(&g_shell->dest->pipe);
	g_shell->dest = g_shell->dest->pipe;
}

void	variable_checker(t_parsing *info)
{
	if (convert_variable(info) && end_of_token(info) && info->state != IN_DOUBLE)
		make_new_token(info);
}

t_bool	end_of_token(t_parsing *info)
{
	return (*(info->ptr + 1) == ' ' || *(info->ptr + 1) == '\0');
}

void	set_state(t_parsing *info)
{
	if (*info->ptr == '\'')
	{
		if (info->state == IN_SINGLE)
			info->state = DULL;
		else
			info->state = IN_SINGLE;
	}
	else if (*info->ptr == '"')
	{
		if (info->state == IN_DOUBLE)
			info->state = DULL;
		else
			info->state = IN_DOUBLE;
	}
	else if (*info->ptr == '|')
		info->state = IN_PIPE;
}
