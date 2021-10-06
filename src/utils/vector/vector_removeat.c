/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_removeat.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 16:47:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/06 19:59:23 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"

/*
	Remove element index from t_vector.
	IMPORTANT: Does not free the memory in case of a pointer!
	The function may overflow, depending on index value.
*/
void	vector_removeat(t_vector *vect, int index)
{
	char	*dest;

	dest = (char *)vect->memb + (index * vect->bytesize);
	ft_memmove(dest, dest + vect->bytesize, \
	(vect->nmemb - index) * vect->bytesize);
	vect->nmemb--;
}
