/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:41:50 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/15 00:07:33 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *buf, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	s = buf;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (buf);
}
