/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_getvalue.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:01:21 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 10:27:23 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"

/*
	Returns the value stored on index.
	The function may overflow, depending on index value.
*/
void	*vector_getvalue(t_vector *vector, int index)
{
	if (vector->isptr)
		return (*((void **)(vector->memb + index * sizeof(void *))));
	return (vector->memb + index * vector->bytesize);
}
