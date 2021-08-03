/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/03 18:18:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "builtin.h"
#include "shell.h"

static char	*st_create_arg(char *key, char *value)
{
	char	*new_arg;
	int		i;
	int		j;

	i = 0;
	while (key[i] != '=' && key[i] != '+')
		i++;
	j = 0;
	while (value[j])
		j++;
	new_arg = malloc(i + j + 2);
	if (!new_arg)
		shell_exit(err_malloc);
	ft_memcpy(new_arg, key, i);
	new_arg[i] = '=';
	ft_memcpy(new_arg + i + 1, value, j);
	new_arg[i + j] = '\0';
	return (new_arg);
}

static char	*st_get_old_arg(char *key, int keylen)
{
	int		i;
	char	*old_arg;

	i = vector_indexof(g_shell->env, key, keylen);
	if (i != -1)
	{
		old_arg = vector_getvalue(g_shell->env, i);
		vector_removeat(g_shell->env, i);
		return (old_arg);
	}
	return (NULL);
}

static t_bool	st_process_arg(char *arg)
{
	char	*value;
	char	*old_arg;
	t_bool	is_append;

	value = ft_strchr(arg, '=');
	if (value == NULL) // no value assignment
		return (true);
	if (arg - value == 0) // no key name
		return (false);
	is_append = false;
	if ((*value - 1) == '+')
		is_append = true;
	old_arg = st_get_old_arg(arg, value - arg - is_append);
	if (is_append)
	{
		arg = ft_strjoin(old_arg, value + 1);
		if (!arg)
			shell_exit(err_malloc);
	}
	else
		arg = st_create_arg(arg, value);
	if (old_arg != NULL)
		free(old_arg);
	vector_add(g_shell->env, arg);
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
