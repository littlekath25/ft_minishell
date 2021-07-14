/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/14 15:11:16 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

// void	remove_one_token(t_tokens *tokens, int index)
// {
// }

// void	expand_tokens(t_tokens *tokens)
// {
// 	char	*new_array;

// 	tokens->allocated *= 2;
// 	new_array = (char *)ft_calloc(tokens->allocated, sizeof(char *));
// 	ft_memcpy(tokens->items, new_array, tokens->size);
// 	free(tokens->items);
// 	tokens->items = new_array;
// }

void	fill_in_tokens(char *line, t_tokens *tokens)
{
	char		*ptr;
	char		*start_of_word;
	int			argc;
	t_states	state;

	state = DULL;
	ptr = line;
	argc = 0;
	while (*ptr)
	{
		if (state == DULL)
		{
			if (*ptr == ' ')
			{
				ptr++;
				continue ;
			}
			else if (*ptr == '"')
			{
				state = IN_STRING;
				start_of_word = ptr + 1;
			}
			else
			{
				state = IN_WORD;
				start_of_word = ptr;
			}
		}
		else if (state == IN_STRING)
		{
			if (*ptr == '"')
			{
				tokens->items[argc] = ft_substr(start_of_word, 0, ptr - start_of_word);
				ptr ++;
				state = DULL;
				argc++;
			}
		}
		else if (state == IN_WORD)
		{
			if (*ptr == ' ')
			{
				state = DULL;
				tokens->items[argc] = ft_substr(start_of_word, 0, ptr - start_of_word);
				argc++;
			}
		}
		ptr++;
	}
	if (state != DULL && *ptr == '\0')
		tokens->items[argc] = ft_substr(start_of_word, 0, ptr - start_of_word);
	int i = 0;
	while (tokens->items[i])
	{
		printf("LINE: %s\n", tokens->items[i]);
		i++;
	}
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
