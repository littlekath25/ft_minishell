/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:30:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/15 20:34:02 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bool	dull_functions(t_parsing *info)
{
	if (*info->ptr == ' ')
		return (true);
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else if (*info->ptr == '|')
	{
		if (info->current_cmd->tokens->items[0] == NULL)
		{
			print_error_token(*info->ptr);
			return (false);
		}
		info->state = IN_PIPE;
	}
	else if (*info->ptr == '$')
		variable_checker(info);
	else if (is_redirect(info))
		return (set_redirects(info));
	else
	{
		info->state = IN_WORD;
		copy_to_buffer(info);
	}
	return (true);
}

void	double_functions(t_parsing *info)
{
	if (*info->ptr == '"' && end_of_token(info))
		make_new_token(info);
	else if (*info->ptr == '"')
		info->state = DULL;
	else if (*info->ptr == '$')
		variable_checker(info);
	else
		copy_to_buffer(info);
}

void	single_functions(t_parsing *info)
{
	if (*info->ptr == '\'' && end_of_token(info))
		make_new_token(info);
	else if (*info->ptr == '\'')
		info->state = DULL;
	else
		copy_to_buffer(info);
}

t_bool	pipe_functions(t_parsing *info)
{
	t_bool	res;

	create_new_pipe(info);
	while (*info->ptr == ' ')
		info->ptr++;
	if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (is_redirect(info))
	{
		res = set_redirects(info);
		info->state = DULL;
		return (res);
	}
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else
	{
		info->state = IN_WORD;
		copy_to_buffer(info);
	}
	return (true);
}

t_bool	word_functions(t_parsing *info)
{
	if (*info->ptr == ' ' || *info->ptr == '|')
	{
		make_new_token(info);
		if (*info->ptr == ' ')
			info->state = DULL;
		else
			info->state = IN_PIPE;
	}
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (*info->ptr == '$')
		variable_checker(info);
	else if (is_redirect(info))
		return (set_redirects(info));
	else
		copy_to_buffer(info);
	return (true);
}
