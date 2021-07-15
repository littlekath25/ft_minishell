/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_getptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:02:06 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 16:30:50 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"

//	Returns a pointer to index in the vector.
void	*vector_getptr(t_vector *vector, int index)
{
	return (vector->memb + index * vector->bytesize);
}
