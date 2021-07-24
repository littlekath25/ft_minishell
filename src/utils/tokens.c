/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/24 12:16:30 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	delete_redirect_token(char **pointers, int i)
{
	pointers[i] = pointers[i + 1];
}

void	expand_token(t_tokens *token)
{
	char	**new;

	token->size = token->allocated;
	token->allocated *= 2;
	new = (char **)ft_calloc(token->allocated, sizeof(char *));
	ft_memcpy(new, token->items, token->size);
	free(token->items);
	token->items = new;
}

void	change_states(t_parsing *info)
{
	if (*(info->ptr) == ' ')
		return ;
	else if (*(info->ptr) == '|')
	{
		info->ptr++;
		if (*(info->ptr) != '\0')
			info->state = IN_PIPE;
		else
			error_and_exit(3);
		return ;
	}
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

void	fill_in_tokens(t_parsing *info, t_tokens *tokens)
{
	info->state = DULL;
	while (*(info->ptr))
	{
		if (info->argc >= tokens->allocated)
			expand_token(tokens);
		if (info->state == DULL)
		{
			change_states(info);
			if (info->state == IN_PIPE)
				return ;
		}
		else if ((info->state == IN_STRING && *(info->ptr) == '"') || \
		(info->state == IN_WORD && *(info->ptr) == ' '))
		{
			tokens->items[info->argc] = \
			ft_substr(info->start, 0, info->ptr - info->start);
			info->state = DULL;
			info->argc++;
		}
		info->ptr++;
	}
	if (info->state != DULL && *(info->ptr) == '\0')
		tokens->items[info->argc] = \
		ft_substr(info->start, 0, info->ptr - info->start);
	info->state = DONE;
}

t_tokens	*create_new_token(void)
{
	t_tokens	*new;

	new = (t_tokens *)ft_calloc(1, sizeof(t_tokens));
	if (!new)
		error_and_exit(1);
	new->size = 0;
	new->allocated = 10;
	new->items = (char **)ft_calloc(new->allocated, sizeof(char *));
	if (!new->items)
		error_and_exit(1);
	return (new);
}
