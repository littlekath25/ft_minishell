/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/01 12:50:29 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../includes/builtin.h"
#include "../../../includes/shell.h"

static t_bool	st_process_arg(char *arg)
{
	t_bool	is_append;
	char	*value;
	int		keylen;
	int		i;

	value = ft_strchr(arg, '=');
	if (value == NULL)
		return (true);
	if (value - arg == 0 || !is_valid_name_l(arg, value - arg))
	{
		printf("pos: %d, isvalid: %d\n", value - arg, is_valid_name_l(arg, value - arg));
		return (false);
	}
	arg = ft_strdup(arg);
	if (!arg)
		error_and_exit(err_malloc);
	keylen = value - arg;
	i = vector_indexof(g_shell->env, arg, keylen);
	if (i != -1)
	{
		free(vector_getvalue(g_shell->env, i));
		vector_removeat(g_shell->env, i);
	}
	vector_add(g_shell->env, arg);
	return (true);
}

/*
	Sets environment variable.
	Overwrites if the variable-name was already present.
*/
void	_export_(char **argv)
{
	char	*arg;

	if (argv[1] == 0)
	{
		_env_(argv);
		return ;
	}
	argv++;
	while (*argv)
	{
		st_process_arg(*argv);
		argv++;
	}
	free(*g_shell->environ);
	*g_shell->environ = vector_tostrarray(g_shell->env);
	if (!*g_shell->environ)
		error_and_exit(err_malloc);
}
