/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_indexof.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 10:41:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 11:06:01 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"

/*
	Seeks in t_vector->memb for specified data, comparing at most len bytes.
	Returns the index of the first element that matches the comparison,
	or -1 if no match has been found.
*/
int	vector_indexof(t_vector *vect, void *data, unsigned int len)
{
	int	i;

	if (len == 0)
		return (-1);
	i = 0;
	while (i < vect->nmemb)
	{
		if (ft_memcmp(vector_getvalue(vect, i), data, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}
