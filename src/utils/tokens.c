/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/10 16:05:35 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	remove_one_token(t_tokens *tokens, int index)
{
}

void	expand_tokens(t_tokens *tokens)
{
	char	*new_array;

	tokens->allocated *= 2;
	new_array = (char *)ft_calloc(tokens->allocated, sizeof(char *));
	ft_memcpy(tokens->items, new_array, tokens->size);
	free(tokens->items);
	tokens->items = new_array;
}

void	fill_in_tokens(char *line, t_tokens *tokens)
{
	char	delimiter;
	char	quotes;

	delimiter = ' ';
	quotes = '"';
	parse_line(line, delimiter, quotes);
}

t_tokens	*create_new_token(void)
{	
	t_tokens	*new;

	new = (t_tokens *)ft_calloc(1, sizeof(t_tokens));
	if (!new)
		error_and_exit(1);
	new->size = 0;
	new->allocated = 10;
	new->items = (char *)ft_calloc(new->allocated, sizeof(char *));
	if (!new->items)
		error_and_exit(1);
	return (new);
}
