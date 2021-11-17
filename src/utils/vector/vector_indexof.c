/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_indexof.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 10:41:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/17 10:53:00 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"
#include "shell.h"
#include <stdio.h>

static char	*cut_key(char *input)
{
	char	*pos;
	char	*result;

	pos = ft_strchr(input, '=');
	if (pos != NULL)
		result = ft_substr(input, 0, (pos - input));
	else
		result = ft_strdup(input);
	if (!result)
		shell_exit(err_malloc);
	return (result);
}

/*
	Seeks in t_vector->memb for specified data.
	Returns the index of the first element that matches the comparison,
	or -1 if no match has been found.
*/
int	vector_indexof(t_vector *vect, char *data)
{
	int		i;
	char	*key;

	i = 0;
	while (i < vect->nmemb)
	{
		key = vector_getvalue(vect, i);
		key = cut_key(key);
		if (ft_strcmp(data, key) == 0)
		{
			free(key);
			return (i);
		}
		free(key);
		i++;
	}
	return (-1);
}
