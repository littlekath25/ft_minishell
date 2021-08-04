/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_tostrarray.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 16:50:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/04 15:23:40 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"
#include <stdlib.h>

/*
	Allocates and copies the values from t_vector to a null-terminated array.
	A pointer to the array is returned. On Error, NULL will be returned.
*/
char	**vector_tostrarray(t_vector *vect)
{
	char	**strs;
	int		i;

	strs = malloc((vect->nmemb + 1) * sizeof(char *));
	if (!strs)
		return (0);
	i = 0;
	while (i < vect->nmemb)
	{
		strs[i] = (char *)vector_getvalue(vect, i);
		if (!strs[i])
		{
			free(strs);
			return (0);
		}
		i++;
	}
	strs[i] = 0;
	return (strs);
}
