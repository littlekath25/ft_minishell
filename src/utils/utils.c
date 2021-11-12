/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 22:16:18 by katherine     #+#    #+#                 */
/*   Updated: 2021/11/12 18:36:15 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	delete_redirect_token(char **pointers, int i)
{
	free(pointers[i]);
	while (pointers[i + 1] != NULL)
	{
		pointers[i] = pointers[i + 1];
		i++;
	}
	pointers[i] = NULL;
}

void	clean_up_tokens(char **pointers, int i)
{
	delete_redirect_token(pointers, i);
	delete_redirect_token(pointers, i);
}

void	print_error_token(char token)
{
	printf("syntax error near unexpected token '%c'\n", token);
}

void	copy_to_buffer(t_parsing *info)
{
	if (info->i >= info->size)
		expand_buffer(info);
	ft_memcpy(&info->buffer[info->i], info->ptr, 1);
	info->i++;
}
