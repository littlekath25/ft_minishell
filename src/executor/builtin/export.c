/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/28 10:52:22 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../includes/builtin.h"
#include "../../../includes/shell.h"

static void	st_process_arg(char *arg)
{
	char	*value;
	int		keylen;
	int		i;

	value = ft_strchr(arg, '=');
	if (value != NULL)
		keylen = value - arg;
	else
		keylen = ft_strlen(arg);
	i = vector_indexof(g_shell->env, arg, keylen);
	if (i != -1)
	{
		free(vector_getvalue(g_shell->env, i));
		vector_removeat(g_shell->env, i);
	}
	vector_add(g_shell->env, arg);
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
		arg = ft_strdup(*argv);
		if (!arg)
			exit(0);
		st_process_arg(arg);
		argv++;
	}
	free(*g_shell->environ);
	*g_shell->environ = vector_tostrarray(g_shell->env);
	if (!*g_shell->environ)
		exit(0);
}
