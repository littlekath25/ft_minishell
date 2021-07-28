/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/28 21:37:50 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	delete_redirect_token(char **pointers, int i)
{
	free(pointers[i]);
	while (pointers[i + 1] != NULL)
	{
		pointers[i] = pointers[i + 1];
		i++;
	}
	pointers[i] = NULL;
}

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
		error_and_exit(3);
}

void	change_states(t_parsing *info)
{
	if (*(info->ptr) == ' ')
		return ;
	else if (*(info->ptr) == '|')
		change_pipe_state(info);
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
	int	ret;

	ret = 0;
	info->state = DULL;
	while (*(info->ptr))
	{
		if (info->argc == (tokens->allocated - 2))
			expand_items(tokens);
		if (info->state == DULL)
		{
			change_states(info);
			if (info->state == IN_PIPE || info->state == ERROR)
				return ;
		}
		ret = check_if_makes_new_item(info);
		if (ret == -1)
			return ;
		else if (ret == 1)
			make_new_item(info, tokens);
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
	new->allocated = 15;
	new->items = (char **)ft_calloc(new->allocated, sizeof(char *));
	if (!new->items)
		error_and_exit(1);
	return (new);
}
