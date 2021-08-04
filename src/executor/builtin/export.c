/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/04 15:16:25 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "builtin.h"
#include "shell.h"

static char	*st_create_new_arg(t_envvar var)
{
	int		keylen;
	int		valuelen;
	char	*new_arg;

	valuelen = 0;
	keylen = ft_strlen(var.key);
	if (var.value)
		valuelen = ft_strlen(var.value) + 1;
	new_arg = malloc(keylen + valuelen + 1);
	if (!new_arg)
		shell_exit(err_malloc);
	ft_memcpy(new_arg, var.key, keylen);
	if (var.value)
	{
		new_arg[keylen] = '=';
		ft_memcpy(new_arg + keylen + 1, var.value, valuelen);
		new_arg[keylen + valuelen] = '\0';
	}
	else
		new_arg[keylen] = '\0';
	return (new_arg);
}

/*
	Checks str for the first occurence of c.
	If no occurence is found, end of the string is returned.
*/
char	*ft_str_contains(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (str);
}

static char	*st_concat_args(char *old_arg, char *value)
{
	char	*new_arg;
	int		needs_delimiter;
	int		old_arg_len;
	int		value_len;

	if (ft_strchr(old_arg, '='))
		needs_delimiter = false;
	else
		needs_delimiter = true;
	old_arg_len = ft_strlen(old_arg);
	value_len = ft_strlen(value);
	new_arg = malloc(old_arg_len + value_len + 1 + needs_delimiter);
	if (!new_arg)
		shell_exit(err_malloc);
	ft_memcpy(new_arg, old_arg, old_arg_len);
	if (needs_delimiter)
		new_arg[old_arg_len] = '=';
	ft_memcpy(new_arg + old_arg_len + needs_delimiter, value, value_len);
	new_arg[old_arg_len + value_len + needs_delimiter] = '\0';
	return (new_arg);
}

static char	*st_get_new_arg(t_envvar var)
{
	char	*old_arg;
	char	*new_arg;
	int		i;

	new_arg = NULL;
	i = vector_indexof(g_shell->env_list, var.key);
	if (i != -1)
	{
		if (!var.value)
			return (NULL);
		old_arg = vector_getvalue(g_shell->env_list, i);
		vector_removeat(g_shell->env_list, i);
		if (var.is_append)
			new_arg = st_concat_args(old_arg, var.value);
		free(old_arg);
	}
	if (new_arg == NULL)
		return (st_create_new_arg(var));
	return (new_arg);
}

static char	*st_split_key(char *arg, t_bool *is_append)
{
	char	*key;
	char	*key_end;
	int		len;

	key_end = ft_str_contains(arg, '=');
	len = key_end - arg;
	if (len == 0)
		return (NULL);
	if (*key_end == '=' && *(key_end - 1) == '+')
	{
		*is_append = true;
		len--;
	}
	else
		*is_append = false;
	key = malloc(len + 1);
	if (!key)
		shell_exit(err_malloc);
	ft_memcpy(key, arg, len);
	key[len] = '\0';
	return (key);
}

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

	var.key = st_split_key(arg, &var.is_append);
	if (is_valid_key(var.key) == false)
	{
		if (var.key)
			free(var.key);
		return (false);
	}
	var.value = st_split_value(arg);
	new_arg = st_get_new_arg(var);
	if (new_arg != NULL)
		vector_add(g_shell->env_list, new_arg);
	free(var.key);
	return (true);
}

/*
	Prints all export variables from environment variables list.
	This includes key-only variables.
*/
void	st_print_export(void)
{
	char	**env;

	env = *g_shell->environ;
	if (!env)
		return ;
	while (*env)
	{
		printf("declare -x %s\n", *env);
		env++;
	}
}

/*
	Sets environment variable.
	Overwrites if the variable-name was already present.
*/
void	_export_(char **argv)
{
	if (argv[1] == 0)
	{
		st_print_export();
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
	*g_shell->environ = vector_tostrarray(g_shell->env_list);
	if (!*g_shell->environ)
		shell_exit(err_malloc);
}
