/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   items.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 21:12:20 by katherine     #+#    #+#                 */
/*   Updated: 2021/09/21 15:44:33 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

// void	make_new_item(t_parsing *info, t_tokens *tokens)
// {
// 	tokens->items[info->argc] = \
// 	ft_substr(info->start, 0, info->ptr - info->start);
// 	info->state = DULL;
// 	info->argc++;
// }

void	expand_items(t_tokens *token)
{
	char	**new;
	int		i;

	i = 0;
	token->size = token->allocated;
	token->allocated *= 2;
	new = (char **)ft_calloc(token->allocated, sizeof(char *));
	while (token->items[i])
	{
		new[i] = token->items[i];
		i++;
	}
	free(token->items);
	token->items = new;
}
