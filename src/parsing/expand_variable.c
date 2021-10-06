/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_variable.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 18:34:05 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/06 15:52:11 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
	Receives a variable name and returns the corresponding value.
	Returns NULL if the key does not exist in the environment variables list.
*/
static char	*expand_variable(char *key)
{
	int		i;
	char	*value;

	if (*key == '?')
		return (ft_itoa(g_shell->returnstatus));
	i = vector_indexof(g_shell->env_list, key);
	if (i != -1)
	{
		value = vector_getvalue(g_shell->env_list, i);
		while (*value && *value != '=')
			value++;
		if (!*value)
			return (NULL);
		value = ft_strdup(value + 1);
		if (value == NULL)
			shell_exit(err_malloc);
		return (value);
	}
	else
		return (NULL);
}

/*
	Takes a pointer to the string line, which should be the starting point of
	the environment variable ($). Increments the pointer while processing.
	Returns the value corresponding to the variable, or NULL if not found.
*/
char	*process_variable(char **line)
{
	char	*key;
	int		i;

	*line += 1;
	i = 0;
	while (ft_isalnum((*line)[i]))
		i++;
	key = malloc(i + 1);
	if (!key)
		shell_exit(err_malloc);
	ft_memcpy(key, *line, i);
	key[i] = '\0';
	*line += i - 1;
	return (expand_variable(key));
}

t_bool	convert_variable(t_parsing *info)
{
	char	*new;
	int		len;

	if (ft_isalnum(*(info->ptr + 1)))
	{
		new = process_variable(&info->ptr);
		if (new == NULL)
			return (false);
	}
	else
		new = ft_strdup("$");
	len = ft_strlen(new);
	ft_memcpy(info->buffer + info->i, new, len);
	info->i += len;
	return (true);
}
