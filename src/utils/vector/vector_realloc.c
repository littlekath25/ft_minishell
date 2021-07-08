/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_realloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:53:02 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 15:59:55 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/vector.h"

t_vector	*vector_realloc(t_vector *vector)
{
	void	*newmemb;

	vector->size *= 2;
	newmemb = ft_calloc(vector->size, vector->bytesize);
	if (!newmemb)
	{
		if (vector->isptr)
			vector_freeptr(vector);
		else
			vector_free(vector);
		return (0);
	}
	ft_memcpy(newmemb, vector->memb, vector->nmemb * vector->bytesize);
	free(vector->memb);
	vector->memb = newmemb;
	return (vector);
}
