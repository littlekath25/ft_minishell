/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:00:20 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 16:30:36 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/vector.h"

//	Add data to vector. If vector needs more memory, it will reallocate.
//	Returns 1 on succes or 0 on error.
char	vector_add(t_vector *vector, void *data)
{
	if (vector->nmemb >= vector->size)
		vector = vector_realloc(vector);
	if (!vector)
		return (0);
	if (vector->isptr)
		ft_memcpy(vector->memb + (vector->nmemb * vector->bytesize),
			(void *)&data, vector->bytesize);
	else
		ft_memcpy(vector->memb + (vector->nmemb * vector->bytesize),
			data, vector->bytesize);
	vector->nmemb += 1;
	return (1);
}
