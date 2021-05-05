/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:41:34 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/15 15:10:13 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char		*d;
	const char			*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const char *)src;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
		if (d[i - 1] == (unsigned char)c)
			return (dest + i);
	}
	return (NULL);
}
