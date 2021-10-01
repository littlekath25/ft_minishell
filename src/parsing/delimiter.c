/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delimiter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:30:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/01 16:08:11 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	dull_functions(t_parsing *info)
{
	if (*info->ptr == ' ')
		return ;
	else if (*info->ptr == '\'')
	{
		info->state = IN_SINGLE;
		info->start = info->ptr + 1;
	}
	else if (*info->ptr == '"')
	{
		info->state = IN_DOUBLE;
		info->start = info->ptr + 1;
	}
	else if (*info->ptr == '|')
		info->state = IN_PIPE;
	else
	{
		info->state = IN_WORD;
		copy_to_buffer(info);
	}
}

void	double_functions(t_parsing *info)
{
	if (*info->ptr == '"')
	{
		make_new_token(info);
		info->state = DULL;
	}
	else if (*info->ptr == '$')
		convert_variable(info);
}

void	single_functions(t_parsing *info)
{
	if (*info->ptr == '\'' && (*(info->ptr + 1) == ' ' || *(info->ptr + 1) == '\0'))
		make_new_token(info);
	else if (*info->ptr == '\'')
	{
		info->state = IN_WORD;
		return ;
	}
	else
		copy_to_buffer(info);
}

void	pipe_functions(t_parsing *info)
{
	if (*info->ptr == ' ')
		return ;
	else if (*info->ptr == '\'')
	{
		info->state = IN_SINGLE;
		info->start = info->ptr + 1;
	}
	else if (*info->ptr == '"')
	{
		info->state = IN_DOUBLE;
		info->start = info->ptr + 1;
	}
	else if (*info->ptr == '|' || *info->ptr == '<' || *info->ptr == '>')
		printf("ERROR\n");
	else
	{
		info->argc = 0;
		info->start = info->ptr;
		info->state = IN_WORD;
		create_new_command_and_tokens(&g_shell->dest->pipe);
		g_shell->dest = g_shell->dest->pipe;
	}
}

void	word_functions(t_parsing *info)
{
	if (*info->ptr == ' ')
	{
		make_new_token(info);
		info->state = DULL;
	}
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else
		copy_to_buffer(info);
}
