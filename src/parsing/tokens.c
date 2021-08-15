/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/08/15 17:19:27 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	delete_redirect_token(char **pointers, int i)
{
	free(pointers[i]);
	while (pointers[i + 1] != NULL)
	{
		pointers[i] = pointers[i + 1];
		i++;
	}
	pointers[i] = NULL;
}

void	fill_in_tokens(t_parsing *info, t_tokens *tokens)
{
	info->state = DULL;
	while (*(info->ptr) == ' ')
		info->ptr++;
	while (*(info->ptr))
	{
		change_states(info, tokens);
		if (info->state == IN_PIPE || info->state == ERROR)
			return ;
		info->ptr++;
	}
	if (*(info->ptr) == '\0' && *(info->ptr - 1) != ' ')
		make_new_item(info, tokens);
	info->state = DONE;
}

t_tokens	*create_new_token(void)
{
	t_tokens	*new;

	new = (t_tokens *)ft_calloc(1, sizeof(t_tokens));
	if (!new)
		shell_exit(1);
	new->size = 0;
	new->allocated = 15;
	new->items = (char **)ft_calloc(new->allocated, sizeof(char *));
	if (!new->items)
		shell_exit(1);
	return (new);
}
