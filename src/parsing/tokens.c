/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/08/01 15:25:37 by kfu           ########   odam.nl         */
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

void	change_states(t_parsing *info, t_tokens *tokens)
{
	if (*(info->ptr) == '|')
		change_pipe_state(info);
	else if (*(info->ptr) == '"')
	{
		if (info->state != IN_DOUBLE && info->state != IN_SINGLE)
		{
			if (info->state != IN_WORD)
				info->start = info->ptr;
			info->state = IN_DOUBLE;
		}
		else
		{
			info->state = DULL;
			info->ptr++;
		}
	}
	else if (*(info->ptr) == '\'')
	{	
		if (info->state != IN_SINGLE && info->state != IN_DOUBLE)
		{
			if (info->state != IN_WORD)
				info->start = info->ptr;
			info->state = IN_SINGLE;
		}
		else
		{
			info->state = DULL;
			info->ptr++;
		}
	}
	else if (info->state == DULL)
	{
		info->start = info->ptr;
		info->state = IN_WORD;
	}
	else if (*(info->ptr) == ' ')
		check_if_makes_new_item(info, tokens);
}

void	fill_in_tokens(t_parsing *info, t_tokens *tokens)
{
	info->state = DULL;
	while (*(info->ptr))
	{
		change_states(info, tokens);
		if (info->state == IN_PIPE || info->state == ERROR)
			return ;
		info->ptr++;
	}
	if (*(info->ptr) == '\0')
		make_new_item(info, tokens);
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
