/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 22:16:18 by katherine     #+#    #+#                 */
/*   Updated: 2021/10/08 13:52:31 by kfu           ########   odam.nl         */
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

void	print_error_token(char token)
{
	printf("syntax error near unexpected token '%c'\n", token);
}

void	copy_to_buffer(t_parsing *info)
{
	ft_memcpy(&info->buffer[info->i], info->ptr, 1);
	info->i++;
}
