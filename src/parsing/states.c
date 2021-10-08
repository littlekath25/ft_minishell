/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:30:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/08 14:01:35 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	dull_functions(t_parsing *info)
{
	if (*info->ptr == ' ')
		return ;
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else if (*info->ptr == '|')
		info->state = IN_PIPE;
	else if (*info->ptr == '$')
		variable_checker(info);
	else if (is_redirect(info))
		make_new_token(info);
	else
	{
		info->state = IN_WORD;
		copy_to_buffer(info);
	}
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
	else if (is_redirect(info))
	{
		print_error_token(*(info->ptr + 1));
		return (0);
	}
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
	{
		printf("syntax error near unexpected token '%c'\n", *(info->ptr + 1));
		return (0);
	}
	else
		copy_to_buffer(info);
	return (1);
}
