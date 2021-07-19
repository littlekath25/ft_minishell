/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 16:59:37 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 10:32:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"
#include <stdlib.h>

/*
	Free's the t_vector struct and vector->memb if not null.
	IMPORTANT: Does not free addresses stored in vector->memb!
	Use vector_clear to take care of that.
*/
void	vector_free(t_vector *vector)
{
	if (vector->memb)
		free(vector->memb);
	free(vector);
}
