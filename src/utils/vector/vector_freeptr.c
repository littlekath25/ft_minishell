/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_freeptr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 15:47:48 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 16:30:48 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/vector.h"

void	vector_freeptr(t_vector *vector)
{
	int	i;

	i = 0;
	while (i < vector->nmemb)
	{
		free(vector_getptr(vector, i));
		i++;
	}
	free(vector);
}
