/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_indexof.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 10:41:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/06 19:59:37 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"
#include <stdio.h>

/*
	Seeks in t_vector->memb for specified data.
	Returns the index of the first element that matches the comparison,
	or -1 if no match has been found.
*/
int	vector_indexof(t_vector *vect, char *data)
{
	int	i;

	i = 0;
	while (i < vect->nmemb)
	{
		if (ft_strncmp(data, vector_getvalue(vect, i), ft_strlen(data)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
