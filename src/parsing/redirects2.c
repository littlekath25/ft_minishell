/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 12:36:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/03 12:37:35 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	set_redirects(void)
{
	t_command	*cmd_ptr;
	char		*token;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	token = NULL;
	cmd_ptr = g_shell->cmd;
	return (iterate_tokens(cmd_ptr, i, ret, token));
}
