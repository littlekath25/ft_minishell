/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_realloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:53:02 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 10:37:03 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/vector.h"

/*
	INTERNAL USE
	Reallocates vector->memb.
*/
t_vector	*vector_realloc(t_vector *vector)
{
	void	*newmemb;

	vector->size *= 2;
	newmemb = ft_calloc(vector->size, vector->bytesize);
	if (!newmemb)
	{
		vector_free(vector);
		return (0);
	}
	ft_memcpy(newmemb, vector->memb, vector->nmemb * vector->bytesize);
	free(vector->memb);
	vector->memb = newmemb;
	return (vector);
}
