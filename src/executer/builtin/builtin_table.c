/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_table.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:27:24 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 12:47:18 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

void	*get_builtin(const char *key)
{
	static t_dict	builtins[] = \
	{
		(t_dict){ .key = "env", .f = env }
	};
	int				i;

	i = 0;
	while (i < 1)
	{
		
	}
}
