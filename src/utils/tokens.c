/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/05 16:13:19 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	expand_tokens(t_tokens *tokens)
{
	
}

void	set_tokens(char *line, t_tokens *tokens)
{
	char	**split;

	split = ft_split_words(line, ' ');
	
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
	new->items = (char **)ft_calloc(10, sizeof(char *));
	if (!new->items)
		error_and_exit(1);
	return (new);
}
