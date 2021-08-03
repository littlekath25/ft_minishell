/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/03 17:43:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "builtin.h"
#include "shell.h"

static char	*st_arg_exists(char *arg)
{
	int		i;

	i = vector_indexof(g_shell->env, arg, keylen);
	if (i != -1)
	{
		cur_arg = vector_getvalue(g_shell->env, i);
		if (is_append)
		{
			new_arg = ft_strjoin(cur_arg, arg + keylen + 2);
			if (!new_arg)
				shell_exit(err_malloc);
		}
		free(cur_arg);
		vector_removeat(g_shell->env, i);
	}
}

static void	st_add_arg(char *arg, int keylen, t_bool is_append)
{
	char	*new_arg;
	char	*cur_arg;

	new_arg = NULL;
	
	if (new_arg == NULL)
	{
		new_arg = malloc(keylen + 1);
		if (!new_arg)
			shell_exit(err_malloc);
		ft_strlcpy(new_arg, arg, keylen + 1);
	}
	vector_add(g_shell->env, new_arg);
	printf("Added: %s\n", new_arg);
}

static t_bool	st_process_arg(char *arg)
{
	t_bool	is_append;
	char	*delimiter;
	int		keylen;

	is_append = false;
	delimiter = ft_strchr(arg, '=');
	if (delimiter == NULL)
		return (true);
	keylen = delimiter - arg;
	if (keylen == 0)
		return (false);
	if (*(delimiter - 1) == '+')
	{
		keylen -= 1;
		is_append = true;
	}
	if (!is_valid_name_l(arg, keylen))
		return (false);
	st_add_arg(arg, keylen, is_append);
	return (true);
}

/*
	Sets environment variable.
	Overwrites if the variable-name was already present.
*/
void	_export_(char **argv)
{
	if (argv[1] == 0)
	{
		_env_(argv);
		return ;
	}
	argv++;
	while (*argv)
	{
		if (st_process_arg(*argv) == false)
			printf("%s: not a valid identifier\n", *argv);
		argv++;
	}
	free(*g_shell->environ);
	*g_shell->environ = vector_tostrarray(g_shell->env);
	if (!*g_shell->environ)
		shell_exit(err_malloc);
	_env_(NULL);
}
