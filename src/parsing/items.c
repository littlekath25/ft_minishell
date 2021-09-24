/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   items.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 21:12:20 by katherine     #+#    #+#                 */
/*   Updated: 2021/09/24 12:51:30 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
