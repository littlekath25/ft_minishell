/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:41:12 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/15 00:45:22 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t blocks, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (blocks < i || size < i)
		return (NULL);
	ptr = malloc(blocks * size);
	if (ptr == NULL)
		return ((void *)0);
	while (i < (blocks * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
