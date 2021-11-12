/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 21:12:20 by katherine     #+#    #+#                 */
/*   Updated: 2021/11/12 18:40:13 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	expand_buffer(t_parsing *info)
{
	char	*new;
	int		old_size;

	old_size = info->size;
	info->size *= 2;
	new = (char *)ft_calloc(sizeof(char), info->size + 1);
	if (!new)
		shell_exit(err_malloc);
	ft_memcpy(new, info->buffer, old_size);
	free(info->buffer);
	info->buffer = new;
}
