/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_toarray.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 16:50:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 10:31:19 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"
#include <stdlib.h>

/*
	Copies the pointers from t_vector to a new null-terminated array.
	Struct t_vector can be freed and data will not be lost.
	Returns NULL on error.
*/
char	**vector_tostrarray(t_vector *vect)
{
	char	**strs;
	int		i;
	int		j;

	strs = malloc((vect->nmemb + 1) * sizeof(char *) );
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
