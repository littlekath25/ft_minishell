/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   items.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 21:12:20 by katherine     #+#    #+#                 */
/*   Updated: 2021/08/02 22:28:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	make_new_item(t_parsing *info, t_tokens *tokens)
{
	tokens->items[info->argc] = \
	ft_substr(info->start, 0, info->ptr - info->start);
	info->state = DULL;
	info->argc++;
}

char	*delete_all_quotes(char *str)
{
	int		size;
	char	*tmp;

	size = count_size_without_quotes(str);
	tmp = (char *)ft_calloc(size + 1, sizeof(char));
	if (!tmp)
		shell_exit(1);
	tmp = copy_str_without_quotes(tmp, str);
	return (tmp);
}

int	check_if_makes_new_item(t_parsing *info, t_tokens *tokens)
{
	if (info->state != IN_DOUBLE && info->state != IN_SINGLE)
		make_new_item(info, tokens);
	return (0);
}

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
