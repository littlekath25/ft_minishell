/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/12 18:36:32 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	realloc_double(t_tokens *tokens)
{
	char	**dest;

	tokens->allocated *= 2;
	dest = ft_calloc(tokens->allocated, sizeof(char *));
	if (!dest)
		shell_exit(err_malloc);
	ft_memcpy(dest, tokens->items, tokens->size * sizeof(char *));
	free(tokens->items);
	tokens->items = dest;
}

void	make_new_token(t_parsing *info)
{
	char		*new;
	t_tokens	*tokens;

	tokens = info->current_cmd->tokens;
	new = ft_strdup(info->buffer);
	if (!new)
		shell_exit(err_malloc);
	if (tokens->size == tokens->allocated - 1)
		realloc_double(tokens);
	tokens->items[tokens->size] = new;
	tokens->size += 1;
	info->state = DULL;
	info->i = 0;
	ft_bzero(info->buffer, info->size);
}

static t_bool	state_action(t_parsing *info)
{
	int	ret;

	ret = true;
	if (info->state == DULL)
		ret = dull_functions(info);
	else if (info->state == IN_SINGLE)
		single_functions(info);
	else if (info->state == IN_DOUBLE)
		double_functions(info);
	else if (info->state == IN_PIPE)
		ret = pipe_functions(info);
	else if (info->state == IN_WORD)
		ret = word_functions(info);
	return (ret);
}

t_bool	fill_in_tokens(t_parsing *info)
{
	while (*info->ptr)
	{
		if (state_action(info) == false)
			return (false);
		if (*info->ptr)
			info->ptr++;
	}
	if (info->state == IN_WORD)
		make_new_token(info);
	return (true);
}
