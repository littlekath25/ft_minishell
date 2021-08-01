/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_valid_name.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 11:37:38 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/01 11:37:53 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bool	is_valid_name(char *var)
{
	if (*var == '_' || ft_isalpha(*var))
	{
		var++;
		while (*var)
		{
			if (ft_isdigit(*var) || ft_isalpha(*var) || *var == '_')
				*var++;
			else
				return (false);
		}
	}
	else
		return (false);
	return (true);
}
