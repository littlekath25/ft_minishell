/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_getvalue.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:01:21 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 16:00:06 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

//	Returns a pointer to index in the vector.
void	*vector_getvalue(t_vector *vector, int index)
{
	if (vector->isptr)
		return (*((void **)(vector->memb + index * sizeof(void *))));
	return (vector->memb + index * vector->bytesize);
}
