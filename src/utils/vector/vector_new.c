/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 15:26:06 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 16:00:11 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/vector.h"

t_vector	*vector_new(int bytesize)
{
	t_vector	*vector;

	vector = ft_calloc(1, sizeof(t_vector));
	if (!vector)
		return (0);
	vector->bytesize = bytesize;
	vector->size = 1;
	vector->memb = ft_calloc(vector->size, vector->bytesize);
	if (!vector->memb)
	{
		free(vector);
		return (0);
	}
	return (vector);
}
