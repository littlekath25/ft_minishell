/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/14 16:49:35 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	change_states(t_parsing *info)
{
	if (*(info->ptr) == ' ')
		return ;
	else if (*(info->ptr) == '"')
	{
		info->state = IN_STRING;
		info->start = info->ptr + 1;
	}
	else
	{
		info->state = IN_WORD;
		info->start = info->ptr;
	}
}

void	create_and_fill_pipe(t_parsing *info)
{
	t_command	*new_pipe;

	new_pipe = create_new_command();
	add_back_command(&g_shell->commands->pipe, new_pipe);
	new_pipe->tokens = create_new_token();
	fill_in_tokens(info->ptr, new_pipe->tokens);
}

void	fill_in_tokens(char *line, t_tokens *tokens)
{
	t_parsing	*info;

	info = (t_parsing *)ft_calloc(sizeof(t_parsing), 1);
	info->ptr = line;
	while (*(info->ptr))
	{
		if (info->state == DULL)
			change_states(info);
		else if ((info->state == IN_STRING && *(info->ptr) == '"') || \
		(info->state == IN_WORD && *(info->ptr) == ' '))
		{
			tokens->items[info->argc] = \
			ft_substr(info->start, 0, info->ptr - info->start);
			info->state = DULL;
			info->argc++;
		}
		else if (*(info->ptr) == '|')
			create_and_fill_pipe(info);
		info->ptr++;
	}
	if (info->state != DULL && *info->ptr == '\0')
		tokens->items[info->argc] = ft_substr(info->start, 0, info->ptr - info->start);
}

t_tokens	*create_new_token(void)
{	
	t_tokens	*new;

	new = (t_tokens *)ft_calloc(1, sizeof(t_tokens));
	if (!new)
		error_and_exit(1);
	new->size = 0;
	new->allocated = 10;
	if (!new->items)
		error_and_exit(1);
	return (new);
}
