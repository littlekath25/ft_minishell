/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/09 11:21:01 by katherine     #+#    #+#                 */
/*   Updated: 2021/09/10 12:46:12 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	change_pipe_state(t_parsing *info)
{
	info->ptr++;
	if (g_shell->cmd->tokens->items[0] == NULL)
	{
		printf("syntax error near unexpected token `|'\n");
		info->state = ERROR;
	}
	else if (*(info->ptr) != '\0')
		info->state = IN_PIPE;
	else
		shell_exit(err_pipe);
}

void	change_double_quotes(t_parsing *info)
{
	if (info->state != IN_DOUBLE && info->state != IN_SINGLE)
	{
		if (info->state != IN_WORD)
			info->start = info->ptr;
		info->state = IN_DOUBLE;
	}
	else
		info->state = IN_WORD;
}

void	change_single_quotes(t_parsing *info)
{
	if (info->state != IN_SINGLE && info->state != IN_DOUBLE)
	{
		if (info->state != IN_WORD)
			info->start = info->ptr;
		info->state = IN_SINGLE;
	}
	else
		info->state = IN_WORD;
}

void	change_states(t_parsing *info, t_tokens *tokens)
{
	if (*(info->ptr) == '|' \
	&& info->state != IN_DOUBLE && info->state != IN_SINGLE)
		change_pipe_state(info);
	else if (*(info->ptr) == '"')
	{
		change_double_quotes(info);
		info->quote = '"';
	}
	else if (*(info->ptr) == '\'')
	{
		change_single_quotes(info);
		info->quote = '\'';
	}
	else if (info->state == DULL && *(info->ptr) != ' ')
	{
		info->start = info->ptr;
		info->state = IN_WORD;
	}
	else if (*(info->ptr) == ' ' && info->state != DULL)
		check_if_makes_new_item(info, tokens);
}
