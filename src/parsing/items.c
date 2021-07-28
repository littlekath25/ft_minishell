/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   items.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 21:12:20 by katherine     #+#    #+#                 */
/*   Updated: 2021/07/27 22:07:13 by katherine     ########   odam.nl         */
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

int	check_if_makes_new_item(t_parsing *info)
{
    int     in_string;

    in_string = 0;
	if (info->state == IN_STRING && *(info->ptr) == '"')
		return (1);
	else if (info->state == IN_WORD && *(info->ptr) == ' ')
		return (1);
	else if (info->state == IN_WORD && *(info->ptr) == '=')
    {
        if (*info->ptr + 1 == '*')
            in_string = 1;
        
		return (2);
    }
	else
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
