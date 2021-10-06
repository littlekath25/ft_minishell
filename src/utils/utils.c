/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 22:16:18 by katherine     #+#    #+#                 */
/*   Updated: 2021/10/06 20:06:05 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	copy_to_buffer(t_parsing *info)
{
	ft_memcpy(&info->buffer[info->i], info->ptr, 1);
	info->i++;
}
