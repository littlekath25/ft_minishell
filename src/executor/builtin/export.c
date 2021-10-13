/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/13 15:42:34 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*st_split_value(char *arg)
{
	arg = ft_strchr(arg, '=');
	if (arg == NULL)
		return (NULL);
	else
		return (arg + 1);
}

static t_bool	st_process_arg(char *arg)
{
	t_envvar	var;
	char		*new_arg;

	var.key = split_key(arg, &var.is_append);
	if (is_valid_key(var.key) == false)
	{
		if (var.key)
			free(var.key);
		return (false);
	}
	var.value = st_split_value(arg);
	new_arg = get_new_arg(var);
	if (new_arg != NULL)
		vector_add(g_shell->env_list, new_arg);
	free(var.key);
	return (true);
}

/*
	Sets environment variable.
	Overwrites if the variable-name was already present.
*/
int	_export_(char **argv)
{
	int	retval;

	retval = 0;
	if (argv[1] == 0)
	{
		export_print();
		return (0);
	}
	argv++;
	while (*argv)
	{
		if (st_process_arg(*argv) == false)
		{
			printf("%s: not a valid identifier\n", *argv);
			retval = 1;
		}
		argv++;
	}
	free(*g_shell->environ);
	*g_shell->environ = vector_tostrarray(g_shell->env_list);
	if (!*g_shell->environ)
		shell_exit(err_malloc);
	return (retval);
}
