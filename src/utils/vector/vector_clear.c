/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_clear.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 10:32:02 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 10:32:10 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"
#include <stdlib.h>

/*
	This is a pointers-vector only function!
	Free's all pointers stored in memb and sets nmemb to 0.
*/
void	vector_clear(t_vector *vect)
{
	int	i;

	if (vect->isptr)
	{
		i = 0;
		while (i < vect->nmemb)
		{
			free(vector_getvalue(vect, i));
			i++;
		}
		vect->nmemb = 0;
	}
}
