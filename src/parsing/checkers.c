/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/09 11:21:01 by katherine     #+#    #+#                 */
/*   Updated: 2021/10/08 13:47:48 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_redirects	which_redirect(char *line)
{
	if (!(ft_strcmp(line, "<")))
		return (INPUT);
	else if (!(ft_strcmp(line, ">")))
		return (OUTPUT);
	else if (!(ft_strcmp(line, "<<")))
		return (DELIMITER);
	else if (!(ft_strcmp(line, ">>")))
		return (APPEND);
	return (NONE);
}

t_bool	is_redirect(t_parsing *info)
{
	if (*info->ptr == '>' || *info->ptr == '<')
	{
		copy_to_buffer(info);
		if (*(info->ptr + 1) == '>' || *(info->ptr + 1) == '<')
		{
			info->ptr++;
			copy_to_buffer(info);
		}
		return (true);
	}
	return (false);
}

void	create_new_pipe(t_parsing *info)
{
	info->argc = 0;
	info->i = 0;
	create_new_command_and_tokens(&g_shell->dest->pipe);
	g_shell->dest = g_shell->dest->pipe;
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
