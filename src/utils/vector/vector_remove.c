/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_remove.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 16:47:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 17:00:50 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"

char	vector_remove(t_vector *vect, int index)
{
	char	*dest;

	dest = (char *)vect->memb + (index * vect->bytesize);
	ft_memmove(dest, dest + vect->bytesize, (vect->nmemb - index) * vect->bytesize);
	vect->nmemb--;
}
