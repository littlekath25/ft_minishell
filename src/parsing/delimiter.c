/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delimiter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:30:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/09/24 13:39:52 by kfu           ########   odam.nl         */
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
	else if (*info->ptr == '$')
		printf("CONVERT ARG\n");
	else if (*info->ptr == '>' || *info->ptr == '<')
		printf("CHANGE REDIRECT\n");
	else
	{
		info->state = IN_WORD;
		info->start = info->ptr;
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
		printf("CONVERT ARG\n");
}

void	single_functions(t_parsing *info)
{
	if (*info->ptr == '\'')
	{
		make_new_token(info);
		info->state = DULL;
	}
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
	else if (*info->ptr == '|')
	{
		make_new_token(info);
		info->state = IN_PIPE;
	}
	else if (*info->ptr == '$')
	{
		make_new_token(info);
		printf("CONVERT ARG\n");
	}
	else if (*info->ptr == '>' || *info->ptr == '<')
		printf("CHANGE REDIRECT\n");
}
