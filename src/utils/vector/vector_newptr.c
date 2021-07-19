/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_newptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:58:01 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 10:36:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"

/*
	Initializes a new t_vector struct with element size of parameter bytesize.
	For vectors storing raw data instead of pointers, use vector_new.
	Returns NULL on error.
*/
t_vector	*vector_newptr(void)
{
	t_vector	*vector;

	vector = vector_new(sizeof(void *));
	if (vector)
		vector->isptr = 1;
	return (vector);
}
