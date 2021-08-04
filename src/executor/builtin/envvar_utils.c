/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_valid_key.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 11:37:38 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/04 16:34:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bool	is_valid_key(char *var)
{
	if (!var)
		return (false);
	if (*var == '_' || ft_isalpha(*var))
	{
		var++;
		while (*var)
		{
			if (ft_isdigit(*var) || ft_isalpha(*var) || *var == '_')
				var++;
			else
				return (false);
		}
	}
	else
		return (false);
	return (true);
}

t_bool	is_valid_key_l(char *var, unsigned int l)
{
	unsigned int	i;

	i = 1;
	if (!var)
		return (false);
	if (*var == '_' || ft_isalpha(*var))
	{
		var++;
		while (*var && i < l)
		{
			if (ft_isdigit(*var) || ft_isalpha(*var) || *var == '_')
				var++;
			else if (*var == '+' && *(var + 1) == '=')
				return (true);
			else
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

/*
	Seeks in t_vector->memb for specified key.
	Returns the index of the first element that matches the comparison,
	or -1 if no match has been found.
*/
int	env_list_indexof(t_vector *vect, char *key)
{
	int		i;
	int		keylen;
	char	*test;

	i = 0;
	keylen = ft_strlen(key);
	while (i < vect->nmemb)
	{
		test = vector_getvalue(vect, i);
		if (ft_strncmp(test, key, keylen) == 0)
			if ((test[keylen] == '=' || test[keylen] == '\0'))
				return (i);
		i++;
	}
	return (-1);
}
