/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 13:58:25 by kfu           #+#    #+#                 */
/*   Updated: 2021/09/21 19:16:25 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	set_delimiters(t_parsing *info)
{
	if (info->state == IN_WORD)
		info->delimiters = "\"' $<>";
	else if (info->state == IN_DOUBLE)
		info->delimiters = "\"$";
	else if (info->state == IN_SINGLE)
		info->delimiters = "'";
	else if (info->state == IN_PIPE)
		info->delimiters = " '\"<>$";
}

static void	state_action(t_parsing *info, t_command *dest)
{
	if (info->state == DULL)
		dull_functions(info, dest);
	else if (info->state == IN_SINGLE)
		single_functions(info);
	else if (info->state == IN_DOUBLE)
		double_functions(info);
	else if (info->state == IN_PIPE)
		pipe_functions(info);
	else if (info->state == IN_WORD)
		word_functions(info, dest);
}

int	fill_in_tokens(t_parsing *info, t_command *dest)
{
	while (*info->ptr)
	{
		set_delimiters(info);
		state_action(info, dest);
		info->ptr++;
	}
	printf("MAKE LAST TOKEN\n");
	return (1);
}
