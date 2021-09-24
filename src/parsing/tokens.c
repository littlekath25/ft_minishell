/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/09/24 13:39:26 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	make_new_token(t_parsing *info)
{
	char	*new;

	new = ft_substr(info->start, 0, info->ptr - info->start);
	g_shell->dest->tokens->items[info->argc] = new;
	info->start = info->ptr;
	info->state = DULL;
	info->argc++;
}

static void	set_delimiters(t_parsing *info)
{
	if (info->state == IN_WORD)
		info->delimiters = "\"' $<>";
	else if (info->state == IN_DOUBLE)
		info->delimiters = "\"$";
	else if (info->state == IN_SINGLE)
		info->delimiters = "'";
	else if (info->state == IN_PIPE)
		info->delimiters = " '\"<>$";
}

static void	state_action(t_parsing *info)
{
	if (info->state == DULL)
		dull_functions(info);
	else if (info->state == IN_SINGLE)
		single_functions(info);
	else if (info->state == IN_DOUBLE)
		double_functions(info);
	else if (info->state == IN_PIPE)
		pipe_functions(info);
	else if (info->state == IN_WORD)
		word_functions(info);
}

int	fill_in_tokens(t_parsing *info)
{
	while (*info->ptr)
	{
		set_delimiters(info);
		state_action(info);
		info->ptr++;
	}
	make_new_token(info);
	return (1);
}
