/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 12:16:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/14 16:32:54 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_command(t_command *new)
{
	new->pipe = NULL;
	new->tokens = NULL;
	new->in_fd = 0;
	new->out_fd = 1;
	new->prev = NULL;
	new->next = NULL;
}

void	add_back_command(t_command **dest, t_command *new)
{
	t_command	*ptr;

	if (*dest == NULL)
		*dest = new;
	else
	{
		ptr = *dest;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}

void	delete_one_command(t_command **src, t_command *node)
{
	if (*src == node)
		*src = (*src)->next;
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free(node);
}

t_command	*create_new_command(void)
{
	t_command	*new;

	new = (t_command *)ft_calloc(1, sizeof(t_command));
	if (new == NULL)
		error_and_exit(2);
	init_command(new);
	return (new);
}
