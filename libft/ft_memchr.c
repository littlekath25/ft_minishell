/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 12:02:32 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:31:41 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *buf, int c, size_t len)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *)buf;
	i = 0;
	if (len > 0)
	{
		while (i < len)
		{
			if (str[i] == (unsigned char)c)
				return ((void *)buf + i);
			i++;
		}
	}
	return (NULL);
}
