/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   items.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 21:12:20 by katherine     #+#    #+#                 */
/*   Updated: 2021/07/31 12:47:25 by katherine     ########   odam.nl         */
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
		error_and_exit(1);
	tmp = copy_str_without_quotes(tmp, str);
	return (tmp);
}

int	env_var_checks(t_parsing *info, int in_string)
{
	while (*info->ptr)
	{
		if (*(info->ptr) == '"' && !in_string)
			in_string = 1;
		else if (*(info->ptr) == '"' && in_string == 1)
		{
			if (*(info->ptr + 1) == '"')
			{
				info->ptr += 2;
				continue ;
			}
			return (1);
		}
		else if (*(info->ptr) == ' ' && in_string == 0)
			return (1);
		info->ptr++;
	}
	if (*info->ptr == '\0' && in_string == 1)
	{
		printf("Error: You have an unclosed quote\n");
		return (-1);
	}
	return (0);
}

int	check_if_makes_new_item(t_parsing *info, t_tokens *tokens)
{
	int		in_string;

	in_string = 0;
	if (info->state == IN_DOUBLE && *(info->ptr) == '"')
		make_new_item(info, tokens);
	else if (info->state == IN_SINGLE && *(info->ptr) == '\'')
		make_new_item(info, tokens);
	else if (info->state == IN_WORD && *(info->ptr) == ' ')
		make_new_item(info, tokens);
	else if (info->state == IN_WORD && *(info->ptr) == '=')
		return (env_var_checks(info, in_string));
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
