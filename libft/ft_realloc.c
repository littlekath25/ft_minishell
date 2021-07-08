/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 13:17:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 12:40:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*cpy;

	if (!ptr)
		return (0);
	if (size > 0)
	{
		cpy = ft_calloc(1, size);
		if (cpy)
			ft_memcpy(cpy, ptr, size);
	}
	else
		cpy = 0;
	free(ptr);
	return (cpy);
}
