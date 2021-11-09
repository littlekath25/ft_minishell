/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:30:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/09 22:58:01 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	dull_functions(t_parsing *info)
{
	if (*info->ptr == ' ')
		return (1);
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else if (*info->ptr == '|')
	{
		if (g_shell->dest->tokens->items[0] == NULL)
		{
			print_error_token(*info->ptr);
			return (0);
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
	return (1);
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

int	pipe_functions(t_parsing *info)
{
	create_new_pipe(info);
	while (*info->ptr == ' ')
		info->ptr++;
	if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else
	{
		info->state = IN_WORD;
		copy_to_buffer(info);
	}
	return (1);
}

int	word_functions(t_parsing *info)
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
	return (1);
}
