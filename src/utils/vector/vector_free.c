/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 16:59:37 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 15:59:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"
#include <stdlib.h>

void	vector_free(t_vector *vector)
{
	if (vector->memb)
		free(vector->memb);
	free(vector);
}
