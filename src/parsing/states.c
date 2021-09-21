/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/09 11:21:01 by katherine     #+#    #+#                 */
/*   Updated: 2021/09/21 16:29:17 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	set_state(t_parsing *info)
{
	if (*info->ptr == '\'')
	{
		if (info->state == IN_SINGLE)
			info->state = DULL;
		else
			info->state = IN_SINGLE;
	}
	else if (*info->ptr == '"')
	{
		if (info->state == IN_DOUBLE)
			info->state = DULL;
		else
			info->state = IN_DOUBLE;
	}
	else if (*info->ptr == '|')
		info->state = IN_PIPE;
}
