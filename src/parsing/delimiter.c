/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delimiter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:30:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/09/21 19:18:35 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	make_new_token(t_parsing *info)
{
	char	*new;

	new = ft_substr(info->start, 0, info->ptr - info->start);
	printf("NEW %s\n", new);
}

void	dull_functions(t_parsing *info, t_command *dest)
{
	if (*info->ptr == ' ')
		return ;
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else if (*info->ptr == '|')
	{
		info->state = IN_PIPE;
		make_new_token(info);
	}
	else if (*info->ptr == '$')
		printf("CONVERT ARG\n");
	else if (*info->ptr == '>' || *info->ptr == '<')
		printf("CHANGE REDIRECT\n");
	else
		info->state = IN_WORD;
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
		printf("MAKE NEW PIPE\n");
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else if (*info->ptr == '|' || *info->ptr == '<' || *info->ptr == '>')
		printf("ERROR\n");
}

void	word_functions(t_parsing *info, t_command *dest)
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
