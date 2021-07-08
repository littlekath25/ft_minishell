/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/08 15:46:48 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	expand_tokens(t_tokens *tokens)
{
	char	**new;

	tokens->allocated *= 2;
	new = (char **)ft_calloc(tokens->allocated, sizeof(char *));
	ft_memcpy(tokens->items, tokens->new, tokens->size);
	free(tokens->items);
}

void	set_tokens(char *line, t_tokens *tokens)
{
	char	**split;
	int		tokens;

	split = ft_split_words(line, ' ', &tokens);
	if (tokens > tokens->allocated)
		expand_tokens(tokens);
}

void	fill_in_tokens(char *line, t_tokens *tokens)
{
	char	**split;
	int		pipes;

	split = ft_split_words(line, '|', &words);
	set_tokens(split[0], tokens);
	ft_free_split(split);
}

t_tokens	*create_new_token(void)
{	
	t_tokens	*new;

	new = (t_tokens *)ft_calloc(1, sizeof(t_tokens));
	if (!new)
		error_and_exit(1);
	new->size = 0;
	new->allocated = 10;
	new->items = (char **)ft_calloc(tokens->allocated, sizeof(char *));
	if (!new->items)
		error_and_exit(1);
	return (new);
}
