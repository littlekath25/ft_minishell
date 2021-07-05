/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 12:16:16 by kfu           #+#    #+#                 */
/*   Updated: 2021/07/02 17:39:04 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_command(t_command *new)
{
	new->pipe = NULL;
	new->tokens = NULL;
	new->in_fd = 0;
	new->out_fd = 1;
	new->previous = NULL;
	new->next = NULL;
}

void	add_back_command(t_command *dest, t_command *new)
{
	t_command	*ptr;

	if (dest == NULL)
		dest = new;
	else
	{
		ptr = dest;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->previous = ptr;
	}
}

void	delete_one_command(t_command *to_delete)
{
	
}

t_command	*create_new_command(t_command *new)
{
	new = (t_command *)ft_calloc(1, sizeof(t_command));
	if (new == NULL)
		error_and_exit(2);
	init_command(new);
	return (new);
}

void	create_commands_list(char *line, t_shell *shell)
{
	t_command	*new;
	char		**split;
	t_bool		quote;
	int			i;

	i = 0;
	split = ft_split(line, '"');
	while (split[i])
	{
		printf("split: %s\n", split[i]);
		i++;
	}
}
