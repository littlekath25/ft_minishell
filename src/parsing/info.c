/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/09 11:22:27 by katherine     #+#    #+#                 */
/*   Updated: 2021/08/09 11:22:39 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_parsing	*create_new_info(char *line)
{
	t_parsing	*new;

	new = (t_parsing *)ft_calloc(sizeof(t_parsing), 1);
	if (!new)
		shell_exit(err_malloc);
	new->ptr = line;
	new->start = NULL;
	new->argc = 0;
	new->state = DULL;
	return (new);
}
