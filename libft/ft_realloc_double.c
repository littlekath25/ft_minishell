/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 15:43:51 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/21 15:50:52 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//	Reallocates memory twice the size of srcsize, and fills the memory with src
//	Either on succes and on error, src will be freed.
//	Return new memory pointer on succes, or NULL on error.
void	*ft_realloc_double(void *src, int srcsize)
{
	char	*dest;
	int		i;

	dest = malloc(srcsize * 2);
	if (!dest)
	{
		free(src);
		return (0);
	}
	i = 0;
	while (i < srcsize)
	{
		dest[i] = ((char *)src)[i];
		i++;
	}
	free(src);
	return (dest);
}
