/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/09 11:21:01 by katherine     #+#    #+#                 */
/*   Updated: 2021/11/15 20:26:48 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bool	is_redirect(t_parsing *info)
{
	if (*info->ptr == '>' || *info->ptr == '<')
		return (true);
	return (false);
}

void	create_new_pipe(t_parsing *info)
{
	info->i = 0;
	create_new_command_and_tokens(&info->current_cmd->pipe);
	info->current_cmd = info->current_cmd->pipe;
}

void	variable_checker(t_parsing *info)
{
	if (convert_variable(info) && \
	end_of_token(info) && info->state != IN_DOUBLE)
		make_new_token(info);
}

t_bool	end_of_token(t_parsing *info)
{
	return (*(info->ptr + 1) == ' ' || *(info->ptr + 1) == '\0');
}
