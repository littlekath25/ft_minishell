/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_newptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 17:58:01 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 16:00:15 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vector	*vector_newptr(void)
{
	t_vector	*vector;

	vector = vector_new(sizeof(void *));
	if (vector)
		vector->isptr = 1;
	return (vector);
}
