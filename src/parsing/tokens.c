/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/08 10:54:46 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	make_new_token(t_parsing *info)
{
	char	*new;

	new = ft_strdup(info->buffer);
	g_shell->dest->tokens->items[info->argc] = new;
	info->state = DULL;
	info->argc++;
	info->i = 0;
	ft_bzero(info->buffer, 1024);
}

static int	state_action(t_parsing *info)
{
	int	ret;

	ret = 1;
	if (info->state == DULL)
		dull_functions(info);
	else if (info->state == IN_SINGLE)
		single_functions(info);
	else if (info->state == IN_DOUBLE)
		double_functions(info);
	else if (info->state == IN_PIPE)
		pipe_functions(info);
	else if (info->state == IN_WORD)
		ret = word_functions(info);
	return (ret);
}

int	fill_in_tokens(t_parsing *info)
{
	while (*info->ptr)
	{
		if (!state_action(info))
			return (0);
		info->ptr++;
	}
	if (info->state == IN_WORD)
		make_new_token(info);
	return (1);
}
