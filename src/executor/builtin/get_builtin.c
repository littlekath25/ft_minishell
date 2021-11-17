/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_builtin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:27:24 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/17 10:06:37 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	*get_builtin(const char *key)
{
	static t_dict	builtins[] = \
	{
		(t_dict){.key = "cd", .f = _cd_},
		(t_dict){.key = "echo", .f = _echo_},
		(t_dict){.key = "env", .f = _env_},
		(t_dict){.key = "exit", .f = _exit_},
		(t_dict){.key = "export", .f = _export_},
		(t_dict){.key = "pwd", .f = _pwd_},
		(t_dict){.key = "unset", .f = _unset_}
	};
	int				i;

	i = 0;
	if (!key)
		return (NULL);
	while (i < 7)
	{
		if (ft_strcmp(builtins[i].key, key) == 0)
			return (builtins[i].f);
		i++;
	}
	return (NULL);
}
